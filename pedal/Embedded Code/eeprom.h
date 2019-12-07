#ifndef EEPROM_H
#define	EEPROM_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdio.h>
#include <stdint.h>
#include "mcc_generated_files/drivers/i2c_master.h"
#include "string.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define CHUNK_SIZE 32

    static const uint8_t PROG_EEPROM = 0x50;
    static const uint16_t PROG_ADDR[8] = {0, 512, 1024, 1536, 2048, 2560, 3072, 3584};
    static const uint8_t DATA_EEPROM = 0x51;
    static const uint16_t DATA_ADDR[16] = {0, 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448, 480};

    typedef struct {
        uint8_t *data;
        uint8_t *dataSize;
    } pageWriteSize_t;

    typedef enum {
        noError = 0, fail_busy, fail_timeout
    } eeprom_ErrNo_t;

    i2c_operations_t write_callback(void *payload) {
        pageWriteSize_t *pgData = payload;
        i2c_setBuffer(pgData->data, *pgData->dataSize);
        i2c_setDataCompleteCallback(NULL, NULL);
        return i2c_continue;
    }

    i2c_operations_t read_callback(void *payload) {
        pageWriteSize_t *pgData = payload;
        i2c_setBuffer(pgData->data, *pgData->dataSize);
        i2c_setDataCompleteCallback(NULL, NULL);
        return i2c_restart_read;
    }

    void EEPROMwrite(uint8_t chipSelect, uint16_t address, uint8_t *data, uint8_t length) {
        uint8_t chunk[CHUNK_SIZE];
        uint8_t size = CHUNK_SIZE;
        uint8_t numChunks = (length % CHUNK_SIZE == 0) ? length / CHUNK_SIZE : length / CHUNK_SIZE + 1;

        for (uint8_t i = 0; i < numChunks; i++) {
            uint8_t copyStart = CHUNK_SIZE*i;
            memcpy(chunk, data + copyStart, CHUNK_SIZE);
            if (length < CHUNK_SIZE * (i + 1)) {
                memset(chunk + (length % CHUNK_SIZE), CHUNK_SIZE - (length % CHUNK_SIZE), 0);
            }
            
            uint8_t addressBytes[2] = {(address >> 8) & 0xFF, address & 0xFF};

            //initiate write with given chip select
            pageWriteSize_t pgData = {0};
            pgData.data = chunk;
            pgData.dataSize = &size;

            while (!i2c_open(chipSelect)); // sit here until we get the bus..
            __delay_ms(10);
            i2c_setDataCompleteCallback(write_callback, &pgData);
            __delay_ms(10);
            i2c_setBuffer(addressBytes, 2);
            __delay_ms(10);
            i2c_setAddressNACKCallback(i2c_restart_write, NULL); //NACK polling?
            __delay_ms(10);
            i2c_masterWrite();
            __delay_ms(10);
            while (I2C_BUSY == i2c_close()); // sit here until finished.
            
            address += CHUNK_SIZE;
            
            //__delay_ms(10);
        }
    }

    void EEPROMread(uint8_t chipSelect, uint16_t address, uint8_t *data, uint8_t length) {
        
        uint8_t addressBytes[2] = {(address >> 8) & 0xFF, address & 0xFF};
        
        pageWriteSize_t pgData = {0};
        pgData.data = data;
        pgData.dataSize = &length;

        while (!i2c_open(chipSelect));
        i2c_setDataCompleteCallback(read_callback, &pgData);
        i2c_setBuffer(addressBytes, 2);
        i2c_setAddressNACKCallback(i2c_restart_write, NULL); //NACK polling?
        i2c_masterWrite();
        while (I2C_BUSY == i2c_close()); // sit here until finished.
    }

#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */


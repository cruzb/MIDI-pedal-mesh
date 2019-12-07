#!/usr/bin/env python3
from tkinter import *
from tkinter import messagebox
from tkinter import filedialog
from tkinter import colorchooser
from tkinter import simpledialog
from PIL import ImageTk, Image
import serial
import serial.tools.list_ports
import os
from pathlib import Path

# PySerial uses UART

bgc = "DeepSkyBlue2"
ebgc = "PaleTurquoise1"


# on change port value
def change_port(*args):
    print(port.get())


class Window(Frame):
    filenameToImport = ""
    # Mac default - for testing
    portNameMac = "/dev/cb.usbserial-00000000"
    # What does it usually show up as on Windows?
    # (Replace '3' with whatever it actually shows up as)
    portNameWindows = "COM3"

    # this defines the window settings
    def __init__(self, master=None):
        Frame.__init__(self, master, background=bgc)
        self.master = master
        self.init_window()

    def init_window(self):

        self.master.title("Pedal Communication Program")

        self.pack(fill=BOTH, expand=1)

        self.filetext = Label(self, text=self.filenameToImport, background=bgc)

        button2 = Button(self, text="Import file", command=self.importFile, background=ebgc)

        button2.place(x=250, y=185, width=100)

        button3 = Button(self, text="SEND EFFECT", command=self.writeToPedal, background=ebgc)
        button3.place(x=250, y=345, width=100)

        menu = Menu(self.master)
        self.master.config(menu=menu)

        option1 = Menu(menu)
        option1.add_command(label="Quit", command=self.exit_thru_menu)
        # option1.add_command(label="Read all inputs", command=self.inputTest)
        # menu.add_cascade(label = "Menu", menu=option1)

        # option2 = Menu(menu)
        # option2.add_command(label = "No", command=self.message2)
        # option2.add_command(label = "Open file", command=self.dataFileTest)
        # menu.add_cascade(label = "Select port", menu=option2)

    def exit_thru_menu(self):
        exit()

    # def showImg(self):
    #     basewidth = 144
    #     load = Image.open("DSPic.png")
    #     load2 = load.resize((160, 80), Image.ANTIALIAS)
    #     render = ImageTk.PhotoImage(load2)
    #
    #     img = Label(self, image=render)
    #
    #     img.image = render
    #
    #     img.place(x=560, y=30)

    def positionInteract(self):
        position = textEntry4.get()
        if position.isnumeric():
            if 0 <= int(position) <= 7:
                return int(position)
            else:
                messagebox.showerror("random title", "Please enter a number within valid address space (0-7)")
                return -1
        else:
            messagebox.showerror("pseudorandom title", "Please enter a number.")
            return -1

    def sourceposInteract(self):
        position = textEntry5.get()
        if (position.isnumeric()):
            if ((int)(position) >= 0 and (int)(position) <= 7):
                return (int)(position)
            else:
                messagebox.showerror("Error", "Please enter a number within valid address space (0-7)")
                return -1
        else:
            messagebox.showerror("Error", "Please enter a number.")
            return -1

    def importFile(self):
        filenameRead = filedialog.askopenfilename()

        infile = open(filenameRead, 'r')
        outfile = open('temp.spn', 'w')
        outfile.write(infile.read())
        infile.close()
        outfile.close()

        if filenameRead != "":
            self.filenameToImport = filenameRead
            # this writes ≈100 spaces to flush out anything there
            filetext = Label(self,
                             text="                                                                                                                               ",
                             background=bgc)
            filetext.place(x=230, y=218)
            filetext = Label(self, text=self.filenameToImport, background=bgc)
            filetext.place(x=230, y=218)

    def writeToPedal(self):

        # ASSEMBLE CODE
        if os.system("asfv1 -s -b temp.spn temp.bin") != 0:
            messagebox.showerror("Error", "" + self.filenameToImport + " could not be assembled")
            return

        #file = open("temp.bin", 'r')
        bindata = Path('temp.bin').read_bytes()

        if len(bindata) != 512:
            messagebox.showerror("Error", "" + "invalid program")
            return

        # Refer to Implementation Notes - Communication Protocol
        portName = port.get()
        ser = serial.Serial(portName)

        #Implement bounds checking before establishing communication
        if (len(textEntryName.get()) > 16):
            messagebox.showerror("Error", "Program name limited to 16 characters")
            return
        if (len(textEntry1.get()) > 4 or len(textEntry2.get()) > 4 or len(textEntry3.get()) > 4):
            messagebox.showerror("Error", "Dial labels limited to 4 characters each")
            return

        # ESTABLISHING COMMUNICATION
        while 1:
            ser.write(b'\xAA')
            response = ser.read(1)
            while response != b'\xAA' or response != b'\x55':
                if response == b'\xAA':
                    break
                response = ser.read(1)
            if response == b'\xAA':
                break

        # SEND TO PEDAL

        # header message
        toSend = chr(slot.get() - 1) + textEntryName.get().ljust(16) + textEntry1.get().ljust(
            4) + textEntry2.get().ljust(4) + textEntry3.get().ljust(4)

        print(bytes(toSend, 'utf-8'))

        cs = 0x00
        i = 0
        while i < len(toSend):
            cs ^= ord(toSend[i])
            i += 1

        print(hex(cs))
        toSend += chr(cs)

        print("SENDING: ")
        print(bytes(toSend, 'utf-8'))
        print("LENGTH: ")
        print(len(toSend))

        while 1:
            ser.write(bytes(toSend, 'utf-8'))
            response = ser.read(1)
            while response != b'\xAA' or response != b'\x55':
                if response == b'\xAA':
                    break
                response = ser.read(1)
            if response == b'\xAA':
                break

        # program data messages
        for i in range(0, 8):

            toSend = bindata[i * 64:(i + 1) * 64]

            cs = 0x00
            i = 0
            while i < len(toSend):
                cs ^= toSend[i]
                i += 1

            print(hex(cs))
            toSend += bytes([cs])

            print("SENDING: ")
            print(toSend)
            # print("SENDING: ")
            # print(bytes(toSend, 'utf-8'))
            print("LENGTH: ")
            print(len(toSend))
            # print("LENGTH: ")
            # print(len(bytes(toSend, 'utf-8')))

            while 1:
                ser.write(toSend)
                # ser.write(bytes(toSend, 'utf-8'))
                response = ser.read(1)
                while response != b'\xAA' or response != b'\x55':
                    if response == b'\xAA':
                        break
                    response = ser.read(1)
                if response == b'\xAA':
                    break


def inputTest(self):
    messagebox.showinfo("Name of effects program to be sent", textEntryName.get())
    messagebox.showinfo("Dial 0 controls", textEntry1.get())
    messagebox.showinfo("Dial 1 controls", textEntry2.get())
    messagebox.showinfo("Dial 2 controls", textEntry3.get())
    messagebox.showinfo("Source file", self.filenameToImport)
    self.positionInteract()


if __name__ == '__main__':
    root = Tk()

    root.geometry("800x400")
    root.config(bg=bgc)

    My_app = Window(root)

    textEntry1 = Entry(root, background=ebgc)
    textEntry1.place(x=200, y=70)
    textEntry2 = Entry(root, background=ebgc)
    textEntry2.place(x=200, y=100)
    textEntry3 = Entry(root, background=ebgc)
    textEntry3.place(x=200, y=130)

    textEntry4 = Entry(root, background=ebgc)
    textEntry4.place(x=275, y=300, width=50)

    textEntry5 = Entry(root, background=ebgc)
    textEntry5.place(x=275, y=260, width=50)

    textEntryName = Entry(root, background=ebgc)
    textEntryName.place(x=200, y=20)

    name1 = Label(root, text="Dial 0 control:", background=bgc)
    name1.place(x=100, y=70)
    name2 = Label(root, text="Dial 1 control:", background=bgc)
    name2.place(x=100, y=100)
    name3 = Label(root, text="Dial 2 control:", background=bgc)
    name3.place(x=100, y=130)

    slot = IntVar(root)
    slots = {1, 2, 3, 4, 5, 6, 7, 8}
    slot.set(1)  # set the default option

    portMenu = OptionMenu(root, slot, *slots)
    portMenu.place(x=80, y=180, width=100)
    portLabel = Label(root, text="Select Storage Slot", background=bgc)
    portLabel.place(x=60, y=160, width=150)

    fileT = Label(root, text="File to send:", background=bgc)
    fileT.place(x=150, y=218)
    # posT = Label(root, text="Address to place in:", background=bgc)
    # posT.place(x=100, y=300)
    # posS = Label(root, text="Address to source from:", background=bgc)
    # posS.place(x=85, y=260)
    nameT = Label(root, text="Name of effects program:", background=bgc)
    nameT.place(x=20, y=20)

    port = StringVar(root)
    ports = [port.device for port in serial.tools.list_ports.comports()]
    print("Connected COM ports: " + str(ports))
    port.set(ports[0])  # set the default option

    portMenu = OptionMenu(root, port, *ports)
    portMenu.place(x=480, y=90, width=300)
    portLabel = Label(root, text="Select Port", background=bgc)
    portLabel.place(x=560, y=60, width=100)

    # link function to change port
    port.trace('w', change_port)

    # systemPortType = IntVar(root)
    # rB1 = Radiobutton(root, text="Mac OS", padx=20, variable=systemPortType, value=1, background=ebgc)
    # rB1.place(x=560, y=120)
    # rB2 = Radiobutton(root, text="Windows", padx=20, variable=systemPortType, value=2, background=ebgc)
    # rB2.place(x=560, y=150)

    # My_app.showImg()

    root.resizable(0, 0)

    root.mainloop()

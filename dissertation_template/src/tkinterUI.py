from tkinter import *

window = Tk()
window.title("Robotic Gripper")
window.geometry('350x200')
window.configure(background='lightblue')
lbl=Label(window, text="Please select a motor", font=("Arial Bold", 15), background='lightblue')
lbl.grid(column=0, row=0)

selected=IntVar()
rad1 = Radiobutton(window, text='Servo', value=1, variable=selected, anchor="w", background='lightblue')
rad2 = Radiobutton(window, text='Dynamixel', value=2, variable=selected, anchor="w", background='lightblue')

radioButtons = [rad1, rad2]
i=3
for rad in radioButtons:
rad.grid(column=0, row=i, sticky="w", padx=10)
i+=1
lblText=StringVar()
lblInfo=Label(window, textvariable=lblText, font=("Arial", 12), justify=LEFT, background='lightblue')
lblInfo.grid(column=0, row=10, sticky="S")

def clicked():
    print(selected.get())
    lbl
    if(selected.get())==1:
      #SERVO
        lblText.set("Hold key 'O' to open claw. \nHold key 'P' to close claw.\nRelease key to stop movement of gripper.")
    elif(selected.get() == 2):
      #Dynamixel
      lblText.set("Touch 'O' key to open claw. \nTouch 'P' key to close claw.\nTouch 'I' key to stop movement.")


btn=Button(window, text="Submit", command=clicked, background='lightblue')
btn.grid(column=0, row=6, sticky="w", padx=10)

window.mainloop()

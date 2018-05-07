#!/usr/bin/env python
# -*- coding: utf-8 -*-
 
from Tkinter import * 
import os

fenetre = Tk()
camera_IHM = Tk()
def callback_orange():
  print "Orange selected !"

def callback_green():
  print "Green selected !"
  os.system("touch green_detected.txt")

def callback_next():


  #photo1 = PhotoImage(file="/home/eliott/Pictures/goldorak-ihm.png")
  #canvas1 = Canvas(camera_IHM,width=480, height=81)
  #canvas1.create_image(0, 0, anchor=NW, image=photo1)
  #canvas1.pack()
  camera_IHM.geometry("480x320+0+0")
  camera_IHM.mainloop()

label = Label(fenetre, text="What color is it ?")
label.pack()

# bouton de sortie
bouton=Button(fenetre, text="Fermer", command=fenetre.quit)
bouton.place(x=430, y=0, width=50, height=25)


# Bouton orange
bt_orange=Button(fenetre, text="Orange", command=callback_orange)
bt_orange.configure(background='orange')
bt_orange.place(x=100, y=150, width=140, height=50)

# Bouton vert
bt_green=Button(fenetre, text="Vert", command=callback_green)
bt_green.configure(background='green')
bt_green.place(x=240, y=150, width=140, height=50)

w, h = fenetre.winfo_screenwidth(), fenetre.winfo_screenheight()
#fenetre.overrideredirect(1)
#fenetre.geometry("%dx%d+0+0" % (w, h))
fenetre.geometry("480x320+0+0")

photo = PhotoImage(file="/home/eliott/Pictures/goldorak-ihm.png")
canvas = Canvas(fenetre,width=480, height=81)
canvas.create_image(0, 0, anchor=NW, image=photo)
canvas.pack()

# Bouton next page
bouton=Button(fenetre, text="Next Page", command=callback_next)
bouton.place(x=410, y=300, width=70, height=25)

#canvas = Canvas(fenetre, width=150, height=120, background='yellow')
#canvas.pack(side=LEFT, padx=100, pady=50)
fenetre.mainloop()

#!/usr/bin/env python
# -*- coding: utf-8 -*-
 
from Tkinter import * 
import os

fenetre = Tk()

def callback_orange():
  print "Orange selected !"

def callback_green():
  print "Green selected !"
  os.system("touch green_detected.txt")

def callback_close_all():
  fenetre.quit

def callback_next():
  camera_IHM = Toplevel()
  photo1 = PhotoImage(file="/home/eliott/Pictures/goldorak-ihm.png")
  canvas1 = Canvas(camera_IHM,width=480, height=81)
  canvas1.create_image(0, 0, anchor=NW, image=photo1)
  canvas1.pack()
  camera_IHM.geometry("480x320+0+0")
  # bouton previous
  bt_previous=Button(camera_IHM, text="Previous Page",command=camera_IHM.destroy)
  bt_previous.place(x=5, y=300, width=100, height=25)

  # Configuration Hue
  label_Hue = Label(camera_IHM, text="Hue")
  label_Hue.place(x=75, y=100, width=70, height=25)
  Hue_min = DoubleVar()
  scale_H_min = Scale(camera_IHM, variable=Hue_min, from_=0, to=255)
  scale_H_min.place(x=50, y=130, width=70, height=100)
  label_Hue_min = Label(camera_IHM, text="Min")
  label_Hue_min.place(x=50, y=250, width=70, height=25)
  Hue_max = DoubleVar()
  scale_H_max = Scale(camera_IHM, variable=Hue_max, from_=0, to=255)
  scale_H_max.place(x=100, y=130, width=70, height=100)
  label_Hue_max = Label(camera_IHM, text="Max")
  label_Hue_max.place(x=100, y=250, width=70, height=25)
  
  # Configuration Saturation
  label_Sat = Label(camera_IHM, text="Sat")
  label_Sat.place(x=225, y=100, width=70, height=25)
  Sat_min = DoubleVar()
  scale_Sat_min = Scale(camera_IHM, variable=Sat_min, from_=0, to=255)
  scale_Sat_min.place(x=200, y=130, width=70, height=100)
  label_Sat_min = Label(camera_IHM, text="Min")
  label_Sat_min.place(x=200, y=250, width=70, height=25)
  Sat_max = DoubleVar()
  scale_Sat_max = Scale(camera_IHM, variable=Sat_max, from_=0, to=255)
  scale_Sat_max.place(x=250, y=130, width=70, height=100)
  label_Sat_max = Label(camera_IHM, text="Max")
  label_Sat_max.place(x=250, y=250, width=70, height=25)

  # Configuration Value
  label_Val = Label(camera_IHM, text="Val")
  label_Val.place(x=375, y=100, width=70, height=25)
  Val_min = DoubleVar()
  scale_Val_min = Scale(camera_IHM, variable=Val_min, from_=0, to=255)
  scale_Val_min.place(x=350, y=130, width=70, height=100)
  label_Val_min = Label(camera_IHM, text="Min")
  label_Val_min.place(x=350, y=250, width=70, height=25)
  Val_max = DoubleVar()
  scale_Val_max = Scale(camera_IHM, variable=Val_max, from_=0, to=255)
  scale_Val_max.place(x=400, y=130, width=70, height=100)
  label_Val_max = Label(camera_IHM, text="Max")
  label_Val_max.place(x=400, y=250, width=70, height=25)
  camera_IHM.mainloop()

# Rotate screen - Ubuntu
#os.system("xrandr -o right")

label = Label(fenetre, text="What color is it ?")
label.pack()

# bouton de sortie
bouton=Button(fenetre, text="Close", command=fenetre.quit)
bouton.place(x=430, y=0, width=50, height=25)

# Bouton orange
bt_orange=Button(fenetre, text="Orange", command=callback_orange)
bt_orange.configure(background='orange')
bt_orange.place(x=100, y=150, width=140, height=50)

# Bouton vert
bt_green=Button(fenetre, text="Green", command=callback_green)
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

fenetre.mainloop()
#fenetre.destroy()

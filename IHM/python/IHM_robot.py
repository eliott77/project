#!/usr/bin/env python
# -*- coding: utf-8 -*-
 
from Tkinter import * 
import os

fenetre = Tk()

def callback_orange():
  print "Orange selected !"
  label = Label(fenetre, text="Thank you: Orange selected !")
  label.place(x=150, y=120, width=200, height=25)

def callback_green():
  print "Green selected !"
  os.system("touch green_detected.txt")
  label = Label(fenetre, text="Thank you: Green selected !")
  label.place(x=150, y=120, width=200, height=25)

def callback_strategy1():
  print "callback_strategy1 !"

def callback_strategy2():
  print "callback_strategy2 !"

def callback_strategy3():
  print "callback_strategy3 !"

def callback_strategy4():
  print "callback_strategy4 !"

def callback_close_all():
  fenetre.quit

def callback_score():
  score_IHM = Toplevel()

  # Image Idle
  photo1 = PhotoImage(file="./pictures/goldorak-ihm.png")
  canvas1 = Canvas(score_IHM,width=480, height=81)
  canvas1.create_image(0, 0, anchor=NW, image=photo1)
  canvas1.pack()
  score_IHM.geometry("480x320+0+0")

  # Select the score required
  label = Label(score_IHM, text="Select a score !")
  label.place(x=180, y=120, width=150, height=25)

  score_IHM.mainloop()

def callback_start():
  start_IHM = Toplevel()
  
  start_IHM.configure(background='orange')
  start_IHM.geometry("480x320+0+0")

  # Insert Label
  label = Label(start_IHM, text="GO GOLDORAK !", bg="orange")
  label.place(x=180, y=120, width=150, height=50)
   
  start_IHM.mainloop()

def callback_camera_display():
  camera_display_IHM = Toplevel()
  #photo1 = PhotoImage(file="./pictures/goldorak-ihm.png")
  #canvas1 = Canvas(camera_display_IHM,width=480, height=81)
  #canvas1.create_image(0, 0, anchor=NW, image=photo1)
  #canvas1.pack()
  camera_display_IHM.geometry("480x320+0+0")
  
  # enable camera
  os.system("fswebcam -d /dev/video0 -r 160x120 --jpeg 85 ./pictures/camera-picture.jpg")
  os.system("sleep 1")
  photo2 = PhotoImage(file="./pictures/camera-picture.jpg")
  canvas2 = Canvas(camera_display_IHM,width=480, height=130)
  canvas2.create_image(0, 0, anchor=NW, image=photo2)
  canvas2.pack()

  # bouton previous
  bt_previous=Button(camera_display_IHM, text="Main Page",command=camera_display_IHM.destroy)
  bt_previous.place(x=5, y=295, width=100, height=25)
  
  camera_display_IHM.mainloop()

def callback_camera_settings():
  camera_IHM = Toplevel()
  photo1 = PhotoImage(file="./pictures/goldorak-ihm.png")
  canvas1 = Canvas(camera_IHM,width=480, height=81)
  canvas1.create_image(0, 0, anchor=NW, image=photo1)
  canvas1.pack()
  camera_IHM.geometry("480x320+0+0")

  # bouton previous
  bt_previous=Button(camera_IHM, text="Main Page",command=camera_IHM.destroy)
  bt_previous.place(x=5, y=295, width=100, height=25)

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

def callback_strategy():
  strategy_IHM = Toplevel()
  photo1 = PhotoImage(file="./pictures/goldorak-ihm.png")
  canvas1 = Canvas(strategy_IHM,width=480, height=81)
  canvas1.create_image(0, 0, anchor=NW, image=photo1)
  canvas1.pack()
  strategy_IHM.geometry("480x320+0+0")
  label = Label(strategy_IHM, text="Select your strategy !")
  label.place(x=180, y=120, width=150, height=25)

  # Bouton Strategy 1
  bt_strg1=Button(strategy_IHM, text="Strategy 1", command=callback_strategy1)
  bt_strg1.configure(background='blue')
  bt_strg1.place(x=100, y=150, width=140, height=50)

  # Bouton Strategy 2
  bt_strg2=Button(strategy_IHM, text="Strategy 2", command=callback_strategy2)
  bt_strg2.configure(background='white')
  bt_strg2.place(x=240, y=150, width=140, height=50)

  # Bouton Strategy 3
  bt_strg3=Button(strategy_IHM, text="Strategy 3", command=callback_strategy3)
  bt_strg3.configure(background='red')
  bt_strg3.place(x=100, y=205, width=140, height=50)

  # Bouton Strategy 4
  bt_strg4=Button(strategy_IHM, text="Strategy 4", command=callback_strategy4)
  bt_strg4.configure(background='purple')
  bt_strg4.place(x=240, y=205, width=140, height=50)

  # bouton previous
  bt_previous=Button(strategy_IHM, text="Main Page",command=strategy_IHM.destroy)
  bt_previous.place(x=5, y=295, width=100, height=25)
  #strategy_IHM.overrideredirect(1)
  strategy_IHM.mainloop()


label = Label(fenetre, text="Select a color !")
label.place(x=180, y=120, width=150, height=25)

# bouton de sortie
bouton=Button(fenetre, text="Close", command=fenetre.quit)
bouton.place(x=5, y=295, width=50, height=25)

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

photo = PhotoImage(file="./pictures/goldorak-ihm.png")
canvas = Canvas(fenetre,width=480, height=81)
canvas.create_image(0, 0, anchor=NW, image=photo)
canvas.pack()

# Bouton Start
bouton=Button(fenetre, text="START", command=callback_start)
bouton.place(x=350, y=175, width=120, height=25)

# Bouton Store
bouton=Button(fenetre, text="Score", command=callback_score)
bouton.place(x=350, y=205, width=120, height=25)

# Bouton camera settings
bouton=Button(fenetre, text="Camera Settings", command=callback_camera_settings)
bouton.place(x=350, y=235, width=120, height=25)

# Bouton camera display
bouton=Button(fenetre, text="Camera Display", command=callback_camera_display)
bouton.place(x=350, y=265, width=120, height=25)

# Bouton Strategy settings
bouton=Button(fenetre, text="Strategy Settings", command=callback_strategy)
bouton.place(x=350, y=295, width=120, height=25)

fenetre.mainloop()


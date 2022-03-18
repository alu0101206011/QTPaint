# SOA QPaint 2022
Made by Anabel Díaz Labrador

# Description
To carry out this practice I have worked in QTCreator.
It is basically a desktop application where you can draw using directional buttons.

## QTCreator
QTCreator has been key to the easy realization of the GUI.
I have worked on 6.0.2v although it can possibly run on 5v.

# How to use?
To run it, simply by having QTCreator, we add the project and click on "Run".

# Code explanation
I have used a given template in the virtual campus to do the practice.
You can find a class to control the application window with one 
method for each direction button. You can also find reading/writing 
configuration methods, these use the QSettings library and it is to 
save configurations once you close the code and read them when you open it.

Then we can also find simple private methods that are menu bar button triggers.

As attributes you can find the ui_ (whole window), pixmap_ (where we paint), 
x_ and y_ (pen coordinates), width_ (width of the pencil painting) 
and colour_ (colour of what the pencil is going to paint).
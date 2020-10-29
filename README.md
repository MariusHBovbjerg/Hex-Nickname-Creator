# Minecraft Hex Colour Nickname Creator
A small program to allow easy to create Hex-colour-coded names in Minecraft using Essentials /nick and coolors.co's gradient creator.

There may be bugs present that I have yet to weed out, as well as some sloppy code.

There are a few things I will be polishing over time, whenever I find time and will to fix em.

The code is functionally ready to work though.


### Tutorial

The program is fairly easy to utilize, once you have gone through it once successfully, 
you shouldn't have an issue doing it over and over. Allowing for easy testing of names.
I'll break it down into a few steps:

0. Preperation 
1. Choosing a colour
2. Setting your name
3. Setting your formatting preference

## 0. Preparation 

If you are only want to use the program, go to /releases/ and download the .exe.

If you want to mess with the code, download the entire thing I suppose 8)

## 1. Choosing your colour

In this step, you want to go to coolors.co and create a pallette or a gradient that you like.

You are limited between 2 and 10 colours on this site, I wanted to expand the possibilities, 
but the site allows for a very nice overview over your choice.

###### NOTE: 
Your chosen colour WILL be darker in Minecraft with the standard font, as MC adds quite a lot of shadow.

## 2. Setting your name

This is very straight forward, choose a name. For best results, make sure your name length is easily divisible by your colour count.

Personally, I like using half the pallette to name length, 12/6 for example.

![](namegradientdifference.png)

######NOTE:
A 9 letter name and a 8 colour pallette will result in only the first 5 colours being used, due to how my algorithm handles pallette resolutions 
at disproportionate and hard to divide size-differences. This is an example, but will work like this whenever there is a relatively small ratio difference.


## 3. Setting your formatting preference

This setting is also quite straight forward, you choose a number between 1-16, corresponding to what setting you want.

Remember that the more formatting you add, the longer your code will be and the more uncertain it'll work on your server.

After you input this piece of data, the code will be in your clipboard.

Format: <code>"/nick [name code]"</code> So you can simply open chat and paste your code.

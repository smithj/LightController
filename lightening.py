#!/usr/bin/python


from time import sleep
import os
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(24, GPIO.IN)

from time import sleep
sleep(1)
while True:
	GPIO.wait_for_edge(24, GPIO.RISING)
	os.system('omxplayer thunder.mp3 &')
	print 'kaboom!'
	sleep(2)


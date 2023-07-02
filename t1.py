import time
import tkinter
import cv2 as cv # 使用cv2来播放视频.
import PIL.Image, PIL.ImageTk


vid_source = mov = r'E:\360MoveData\Users\Administrator\Desktop\海贼王第1066集.mp4'
vid=cv.VideoCapture(vid_source)


cnt=0
while 1:
    ret, frame = vid.read()
    cnt+=1
print(cnt)
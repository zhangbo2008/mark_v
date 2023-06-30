import tkinter as tk
vid='E:/video/byxOvuiIJV0.mp4'
from tkVideoPlayer import TkinterVideo
root = tk.Tk()
videoplayer = TkinterVideo(master=root, scaled=True)
videoplayer.load(vid)
videoplayer.pack(expand=True, fill="both")
videoplayer.play() # play the video
root.mainloop()
import time
import tkinter
import cv2 as cv # 使用cv2来播放视频.
import PIL.Image, PIL.ImageTk


class App:
    # 将类作为参数传入
    # app = App(tkinter.Tk(), "tkinter player", 'test.mp4')
    def __init__(self, window, window_title, video_source=''):
        self.photo = None
        self.window = window    # window = tkinter.Tk()
        self.window.title = window_title # tkinter.Tk().title() = window_title
        self.video_source = 0 if not video_source else video_source # 这里用if else not是为了避免，python传参的警告
        self.vid = myvideocapture(self.video_source)
        # Canvas in window, 1080*1080——> window_size >= canvas
        self.canvas = tkinter.Canvas(window, width=self.vid.width, height=self.vid.height, )    # 设置画布，窗口大小>=画布大小
        self.canvas.pack()  # pack()方法布局，还有place等方法替代

        # add  buttons
        self.btn_pause = tkinter.Button(window, text='pause', width=50, command=self.pause) # command对应button绑定的事件
        self.btn_pause.pack(anchor=tkinter.CENTER, fill=tkinter.Y, side=tkinter.RIGHT, expand=True)
        # self.btn_pause.pack(anchor=tkinter.CENTER, fill=tkinter.Y, expand=True)
        self.btn_play = tkinter.Button(window, text='play', width=50, command=self.play)
        self.btn_play.pack(anchor=tkinter.CENTER, fill=tkinter.Y, side=tkinter.LEFT, expand=True)
        # self.btn_play.pack(anchor=tkinter.CENTER, fill=tkinter.Y, expand=True)
        # flag control video player




        self.flag = 1
        self.delay = int(100 / (self.vid.fps) + 0.5)
        print(self.delay,'间隔')
        self.update()
        self.window.mainloop() # 启动tkinter界面.

    def update(self):
        """

        :return:
        """
        ret, frame = self.vid.get_frame()
        if ret:
            self.photo = PIL.ImageTk.PhotoImage(image=PIL.Image.fromarray(frame))
            self.canvas.create_image(0, 0, image=self.photo, anchor=tkinter.NW)
        # 设置暂停播放flag
        if self.flag:
            self.window.after(self.delay, self.update)

    def pause(self):
        """

        :return:
        """
        self.flag = 0

    def play(self):
        """

        :return:
        """
        self.flag = 1
        self.window.after(self.delay, self.update)


class myvideocapture:
    def __init__(self, vid_source=''):
        # 避免之前的，传参的问题
        self.vid = cv.VideoCapture(0) if not vid_source else cv.VideoCapture(vid_source)
        if not self.vid.isOpened():
            raise ValueError('unable to open video source!', vid_source)
        self.width = self.vid.get(cv.CAP_PROP_FRAME_WIDTH)
        self.height = self.vid.get(cv.CAP_PROP_FRAME_HEIGHT)
        self.fps = self.vid.get(cv.CAP_PROP_FPS)
        self.fps_all = self.vid.get(cv.CAP_PROP_FRAME_COUNT)
        print('视频',self.width,self.height,self.fps,self.fps_all)

    def __del__(self):
        if self.vid.isOpened():
            self.vid.release()

    def get_frame(self):
        if self.vid.isOpened():
            ret, frame = self.vid.read()  #每一次读取一个图片
            #=======chuli:
            # frame = cv.flip(frame, 0)
            if ret:
                # opencv——BGR(blue-green-red)
                # PIL, matplotlib——(RGB)
                return (ret, cv.cvtColor(frame, cv.COLOR_BGR2RGB))
            else:
                return (ret, None)
        else:
            return None

vid=mov=r'E:\360MoveData\Users\Administrator\Desktop\海贼王第1066集.mp4'
if __name__ == '__main__':
    app = App(tkinter.Tk(), "tkinter player",vid)


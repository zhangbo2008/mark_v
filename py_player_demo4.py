# 2023-07-02,13点25 时间轴修改成帧数.方便后期定位. 现实时间我不关心, 我只用帧来衡量时间
#=======下一个就是力度问题. 每次拖拽的力度只能百分之1, 这个很烦.解决了用self.maxi 参数设置. 越大力度月小.

# mp4电影资源下载:http://www.8080s.tv/dm/3108  
#=======下面我们做一个标注记录帧即可.



from PyQt5.QtWidgets import *
from PyQt5.QtMultimedia import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtMultimediaWidgets import QVideoWidget
from GUI import Ui_MainWindow
from myVideoWidget import myVideoWidget
import sys

from PyQt5 import QtCore, QtGui, QtWidgets
class myMainWindow(Ui_MainWindow, QMainWindow):
    def __init__(self):
        super(Ui_MainWindow, self).__init__()
        self.setupUi(self)
        self.maxi=1000 #===这个控制整体切分力度. 我感觉把一个视频切1000分足够细化了.
        self.sld_video_pressed=False  #判断当前进度条识别否被鼠标点击
        self.videoFullScreen = False   # 判断当前widget是否全屏
        self.videoFullScreenWidget = myVideoWidget()   # 创建一个全屏的widget
        self.player = QMediaPlayer()
        # self.player2 = QtWidgets.QPushButton(self.splitter) #添加按钮的写法.

        self.player.setVideoOutput(self.wgt_video)  # 视频播放输出的widget，就是上面定义的
        self.btn_open.clicked.connect(self.openVideoFile)   # 打开视频文件按钮
        self.btn_play.clicked.connect(self.playVideo)       # play
        self.btn_stop.clicked.connect(self.pauseVideo)       # pause
        self.btn_cast.clicked.connect(self.castVideo)        # 视频截图
        self.player.positionChanged.connect(self.changeSlide)  # change Slide
        
        self.videoFullScreenWidget.doubleClickedItem.connect(self.videoDoubleClicked)  #双击响应
        self.wgt_video.doubleClickedItem.connect(self.videoDoubleClicked)  #双击响应
        
#============进度条的控制是我们要做的核心.
        self.sld_video.setTracking(True)
        self.flag=1
        self.sld_video.sliderReleased.connect(self.releaseSlider)
        self.sld_video.sliderPressed.connect(self.pressSlider)
        self.sld_video.sliderMoved.connect(self.moveSlider)   # 进度条拖拽跳转
        self.sld_video.ClickedValue.connect(self.clickedSlider)  # 进度条点击跳转
#参考:https://doc.qt.io/qtforpython-5/PySide2/QtWidgets/QAbstractSlider.html#qabstractslider   好资料:https://zhuanlan.zhihu.com/p/75657373


        self.sld_audio.valueChanged.connect(self.volumeChange)  # 控制声音播放
        self.btn_cast.hide()
        import PyQt5.QtCore as QtCore
        #=========默认打开一个.方便调试#=========================这里进行初始化调试!!!!!!!!!!!!!!!!!
        if 1:
            stream = QtCore.QUrl.fromLocalFile("sample.mp4")
            self.player.setMedia(QMediaContent(stream))

            ######===========
            self.player.play()
            self.player.pause()#=============上来输入暂停,才让视频开始读取!!!!!!!!!!
            # self.sld_video.setRange(0,100)
            print(self.player.duration(), 8888888)

        # print('当前文件的时间', self.player.duration())
        # self.player.durationChanged.connect(lambda x:print(x))
        
        self.sld_video.setMaximum(self.maxi)
        self.sld_video.setMinimum(0)  #控制切分力度的.
        
        print(self.sld_video.maximum(),222222222222222222222222222222222222222222222222)
        print(self.sld_video.minimum(),333333333333333333333333333333333333)
        print(self.sld_video.setSingleStep(1))
        print(self.player.duration(), 'begin_duration')
        sav_dur=0


    
    def castVideo(self):
        screen = QGuiApplication.primaryScreen()
        cast_jpg = './'+QDateTime.currentDateTime().toString("yyyy-MM-dd hh-mm-ss-zzz")+'.jpg'
        screen.grabWindow(self.wgt_video.winId()).save(cast_jpg)

    def volumeChange(self, position):
        volume= round(position/self.sld_audio.maximum()*self.maxi)
        print("vlume %f" %volume)
        self.player.setVolume(volume)
        self.lab_audio.setText("volume:"+str(volume)+"%")

    def clickedSlider(self, position):
        print('你当前传入的位置是.', position)
        print(self.sld_video.hasTracking(),9999999999)
        if 1:  # 开始播放后才允许进行跳转
            print(11111111111111111, self.player.duration())
            
            video_position = int((position / self.maxi) * self.player.duration())
            self.player.setPosition(video_position)
            self.lab_video.setText( str((position)))
        else:
            self.sld_video.setValue(0)

    def moveSlider(self, position):
        self.sld_video_pressed = True
        print('moveslider',position)
        # print(1111111111111111111111111111111111,213123123123123)
        if 1:  # 开始播放后才允许进行跳转
            print('11111111vvvvvvvvvvv',position)
            video_position = int((position / self.maxi) * self.player.duration())
            print('vvvvvvvvvvvvv',video_position)
            self.player.setPosition(video_position)

            self.vidoeLength = self.player.duration() + 0.00000001
            self.lab_video.setText( str(int((position)/self.maxi*self.vidoeLength) ))

    def pressSlider(self):
        self.sld_video_pressed = True
        print("pressed")

    def releaseSlider(self):
        self.sld_video_pressed = False

    def changeSlide(self, position):  #视频流逝时候更新这个函数..
        # print('check, duration', self.player.duration())
        
        # self.sav_dur = self.player.duration()  #=====每步都更新.把变量给别人用.
        if self.flag:
            #========最开始的进行初始化一次.
            self.sld_video.setMaximu=self.player.duration()
            self.sld_video.setRange=(0,self.player.duration())
            self.sld_video.setTickPosition='QSlider::TicksAbove'
            print(self.sld_video.setMaximu,88888888888888888888888)


            self.flag=0

        if not self.sld_video_pressed:  # 进度条被鼠标点击时不更新
            self.vidoeLength = self.player.duration() + 0.00000001
            print('reunning', position)
            self.sld_video.setValue(((position/self.vidoeLength)*self.maxi))
            #当前位置除以整个长度. #========让进度条跟着跑.
            self.lab_video.setText( str((position)))









    def openVideoFile(self):
        self.player.setMedia(QMediaContent(QFileDialog.getOpenFileUrl()[0]))  # 选取视频文件
        self.player.play()  # 播放视频
        print(self.player.availableMetaData())

    def playVideo(self):
        # print(self.duration,999999999999999)
        # print(self.MediaStatus,3423)
        print(self.player.state(),33333333333333333)

        self.player.play()
    def pauseVideo(self): ########=========修改为点暂停按钮就是启动和暂停功能.
        if self.player.state() != 1:
            self.player.play()
        else:
            self.player.pause()

    def videoDoubleClicked(self, text):

        if self.player.duration() > 0:  # 开始播放后才允许进行全屏操作
            if self.videoFullScreen:#已经全屏了就切回来
                self.player.setVideoOutput(self.wgt_video)
                self.videoFullScreenWidget.hide()
                self.videoFullScreen = False
            else:#不是全屏就切全屏.
                self.videoFullScreenWidget.show()
                self.player.setVideoOutput(self.videoFullScreenWidget)
                self.videoFullScreenWidget.setFullScreen(1)
                self.videoFullScreen = True


if __name__ == '__main__':
    app = QApplication(sys.argv)
    vieo_gui = myMainWindow()
    vieo_gui.show()
    print(vieo_gui.player.duration(),423874623874623784623784)
    sys.exit(app.exec_())
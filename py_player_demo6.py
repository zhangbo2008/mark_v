# 2023-07-02,13点25 时间轴修改成帧数.方便后期定位. 现实时间我不关心, 我只用帧来衡量时间
#=======下一个就是力度问题. 每次拖拽的力度只能百分之1, 这个很烦.解决了用self.maxi 参数设置. 越大力度月小.

# mp4电影资源下载:http://www.8080s.tv/dm/3108
# 测试的海贼王1066视频:  https://huggingface.co/datasets/zhangbo2008/one_piece_1066/resolve/main/%E6%B5%B7%E8%B4%BC%E7%8E%8B%E7%AC%AC1066%E9%9B%86.mp4   可以wget直接下载.
#2023-07-05,19点47   添加键盘左右箭头对于时间的控制.
mov=r'E:\人生路不熟.mp4'
# mov=r'sample.mp4'
#==========qt官方文档:https://doc.qt.io/qtforpython-5/
'''
#========整个qt相应逻辑:
# 1. player.positionChanged 控制视频自动播放个时候的进度条逻辑.
        只有当鼠标不点击进度条的时候我们才进行更新.
        如果鼠标点击进度条那么我们就会调用clickedSlider函数,这时player会锁定位置了.setposition
        如果鼠标拖动进度条我们会调用moveslider函数,player也会相应锁定新的图片位置.
        (整个逻辑很完美)
  2. 键盘调整------>调用ClickedValue2----->调用moveslider函数.
        (moveslider逻辑确实复杂, 里面涉及一个时间轴是否按下的判断.底层也没完全理解. 以为键盘时候也会判定为按下鼠标所以这时候时间轴CIA不会乱跑.目前这个逻辑完美, 后续更新在看吧.)


'''







from PyQt5.QtWidgets import *
from PyQt5.QtMultimedia import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtMultimediaWidgets import QVideoWidget
from GUI import Ui_MainWindow
from myVideoWidget2 import myVideoWidget
import sys

from PyQt5 import QtCore, QtGui, QtWidgets
class myMainWindow(Ui_MainWindow, QMainWindow):
    from PyQt5 import QtCore
    ClickedValue2 = pyqtSignal(int)
    def keyPressEvent(self, event):
        print(self.value(),3423423423423)
        print(1111)
        if event.key()==Qt.Key_Right:
            self.setValue(self.value() + 1)
            print(self.value(),3423423423423)

        elif event.key()==Qt.Key_Left:
            self.setValue(self.value() - 1)
            print(self.value(),3423423423423)
        if event.key() == Qt.Key_PageDown:
            self.setValue(self.value() - 5)
        if event.key()==Qt.Key_PageUp:
            self.setValue(self.value() + 5)
        self.ClickedValue2.emit(self.value())
    def __init__(self):
        super(Ui_MainWindow, self).__init__()
        self.setupUi(self)
        self.for_key=0
        self.front = []
        self.end = []
        self.tmpframe=0
        #===========添加我的新按钮:
        if 1:
            from PyQt5 import QtCore
            _translate = QtCore.QCoreApplication.translate
            self.btn_front = QtWidgets.QPushButton(self.splitter)
            self.btn_front.setMaximumSize(QtCore.QSize(200, 250))
            self.btn_front.setObjectName("btn_front")
            self.btn_front.setText(_translate("MainWindow", "add left key"))


            self.btn_end = QtWidgets.QPushButton(self.splitter)
            self.btn_end.setMaximumSize(QtCore.QSize(200, 250))
            self.btn_end.setObjectName("btn_end")
            self.btn_end.setText(_translate("MainWindow", "add right key"))

            self.btn_front.clicked.connect(self.btn_front1)
            self.btn_end.clicked.connect(self.btn_end1)



            _translate = QtCore.QCoreApplication.translate
            self.btn_s = QtWidgets.QPushButton(self.splitter)
            self.btn_s.setMaximumSize(QtCore.QSize(200, 250))
            self.btn_s.setObjectName("btn_s")
            self.btn_s.setText(_translate("MainWindow", "save to out.txt"))
            self.btn_s.clicked.connect(self.btn_s1)







        if 1:  #加入提示:
                    self.helper = QtWidgets.QLabel(self.centralwidget)
                    self.helper.setMaximumSize(QtCore.QSize(16777215, 50))
                    self.helper.setObjectName("helper")
                    self.helper.setText(_translate("MainWindow", "当前为空标注"))
                    self.gridLayout.addWidget(self.helper, 3, 1, 1, 1)








        self.maxi=2000 #===这个控制整体切分力度. 我感觉把一个视频切1000分足够细化了.
        self.sld_video_pressed=False  #判断当前进度条识别否被鼠标点击
        self.videoFullScreen = False   # 判断当前widget是否全屏
        self.videoFullScreenWidget = myVideoWidget()   # 创建一个全屏的widget
        self.player = QMediaPlayer()
        # self.player2 = QtWidgets.QPushButton(self.splitter) #添加按钮的写法.

        self.player.setVideoOutput(self.wgt_video)  # 视频播放输出的widget，就是上面定义的
        self.btn_open.clicked.connect(self.openVideoFile)   # 打开视频文件按钮
        # self.btn_play.clicked.connect(self.playVideo)       # play
        self.btn_stop.clicked.connect(self.pauseVideo)       # pause
        self.btn_cast.clicked.connect(self.castVideo)        # 视频截图
        self.player.positionChanged.connect(self.changeSlide)  # change Slide
        
        self.videoFullScreenWidget.doubleClickedItem.connect(self.videoDoubleClicked)  #双击响应
        self.wgt_video.doubleClickedItem.connect(self.videoDoubleClicked)  #双击响应
        
#============进度条的控制是我们要做的核心.!!!!!!!!!!!!!!最核心的是下面4个connect的4个函数
        self.sld_video.setTracking(True)
        self.flag=1
        self.sld_video.sliderReleased.connect(self.releaseSlider)
        self.sld_video.sliderPressed.connect(self.pressSlider)
        self.sld_video.sliderMoved.connect(self.moveSlider)   # 进度条拖拽跳转
        self.sld_video.ClickedValue.connect(self.clickedSlider)  # 进度条点击跳转
        self.sld_video.ClickedValue2.connect(self.moveSlider)  # 进度条点击跳转
        
        # def fun(a):
        #     self.sld_video.super().keyPressEvent(QKeyEvent)
        #     print(a)
        # self.sld_video.keyPressEvent = fun
        # print(self.sld_video.keyPressEvent,3333333333)
        







#参考:https://doc.qt.io/qtforpython-5/PySide2/QtWidgets/QAbstractSlider.html#qabstractslider   好资料:https://zhuanlan.zhihu.com/p/75657373


        self.sld_audio.valueChanged.connect(self.volumeChange)  # 控制声音播放
        self.btn_cast.hide()
        import PyQt5.QtCore as QtCore
        #=========默认打开一个.方便调试#=========================这里进行初始化调试!!!!!!!!!!!!!!!!!
        if 1:
            stream = QtCore.QUrl.fromLocalFile(mov)
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
        self.sld_video.setTickInterval(10)
        self.sld_video.setSingleStep(1) #=======很奇怪这里居然是2. 才表示1000分支1.....
        self.sld_video.setPageStep(20) #=======很奇怪这里居然是2. 才表示1000分支1.....
        print(self.sld_video.singleStep(),33333333333333)
        # print(self.sld_video.maximum(),222222222222222222222222222222222222222222222222)
        # print(self.sld_video.minimum(),333333333333333333333333333333333333)

        # print(self.player.duration(), 'begin_duration')
        sav_dur = 0
        

    _translate = QtCore.QCoreApplication.translate
    def btn_front1(self):
        _translate = QtCore.QCoreApplication.translate
        self.front.append(self.tmpframe)


        self.helper.setText(_translate("MainWindow", f"左{len(self.front)} 右{len(self.end)}"))
        # print('fornt',self.front)

    def btn_end1(self):
        _translate = QtCore.QCoreApplication.translate
        self.end.append(self.tmpframe)
        self.helper.setText(_translate("MainWindow", f"左{len(self.front)} 右{len(self.end)}"))
        # print('end',self.end)

    def btn_s1(self):
        _translate = QtCore.QCoreApplication.translate
        with open('out.txt', 'w') as f:
            for i in range(len(self.front)):
                    f.write(str(self.front[i])+' '+str(self.end[i])+'\n')
        self.helper.setText(_translate("MainWindow", f"保存完毕"))

    
    def castVideo(self):
        screen = QGuiApplication.primaryScreen()
        cast_jpg = './'+QDateTime.currentDateTime().toString("yyyy-MM-dd hh-mm-ss-zzz")+'.jpg'
        screen.grabWindow(self.wgt_video.winId()).save(cast_jpg)

    def volumeChange(self, position):
        volume= round(position/self.sld_audio.maximum()*100)
        # print("vlume %f" %volume)
        self.player.setVolume(volume)
        self.lab_audio.setText("volume:"+str(volume)+"%")
    def clickedSlider2(self, position):
        video_position = int((position / self.maxi) * self.player.duration())
        print(video_position, '调试!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
        # self.for_key=1
        self.player.setPosition(video_position) 
        video_position = int((position / self.maxi) * self.player.duration())
        
        self.lab_video.setText( str((video_position)))
        print('你当前传入的位置是.', position)
        # self.for_key=0







    def clickedSlider(self, position):

        print('你当前传入的位置是.', position)
        # print(self.sld_video.hasTracking(),9999999999)
        if 1:  # 开始播放后才允许进行跳转
            print(11111111111111111, self.player.duration())
            
            video_position = int((position / self.maxi) * self.player.duration())
            print(video_position,'调试!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
            self.player.setPosition(video_position)
            self.lab_video.setText( str((video_position)))
        else:
            self.sld_video.setValue(0)
        self.tmpframe = position
        




    def moveSlider(self, position):
        self.sld_video_pressed = True
        # print('moveslider',position)
        # print(1111111111111111111111111111111111,213123123123123)
        if 1:  # 开始播放后才允许进行跳转
            # print('11111111vvvvvvvvvvv',position)
            video_position = int((position / self.maxi) * self.player.duration())
            # print('vvvvvvvvvvvvv',video_position)
            self.player.setPosition(video_position)

            self.vidoeLength = self.player.duration() + 0.00000001
            self.lab_video.setText( str(int((position)/self.maxi*self.vidoeLength) ))
        self.tmpframe = position
    
    def pressSlider(self):
        self.sld_video_pressed = True
        # print("pressed")

    def releaseSlider(self):
        self.sld_video_pressed = False
        print('触发了release')

    def changeSlide(self, position):  #视频流逝时候更新这个函数..
        # print('check, duration', self.player.duration())
        
        # self.sav_dur = self.player.duration()  #=====每步都更新.把变量给别人用.
        if self.flag:
            #========最开始的进行初始化一次.
            self.sld_video.setMaximu=self.player.duration()
            self.sld_video.setRange=(0,self.player.duration())
            self.sld_video.setTickPosition='QSlider::TicksAbove'
            # print(self.sld_video.setMaximu,88888888888888888888888)


            self.flag=0
        print(self.for_key,333333333333333333333333333333333333333333)
        if not self.sld_video_pressed and not self.for_key:  # 进度条被鼠标点击时不更新
            print('触发了进度条')
            self.vidoeLength = self.player.duration() + 0.00000001
            # print('reunning999999999999999999999999999999999999999999999999', position)
            self.sld_video.setValue(((position/self.vidoeLength)*self.maxi))
            #当前位置除以整个长度. #========让进度条跟着跑.
            self.lab_video.setText(str((position)))
        self.tmpframe=position









    def openVideoFile(self):
        self.player.setMedia(QMediaContent(QFileDialog.getOpenFileUrl()[0]))  # 选取视频文件
        self.player.play()  # 播放视频
        # print(self.player.availableMetaData())

    def playVideo(self):
        # print(self.duration,999999999999999)
        # print(self.MediaStatus,3423)
        (self.player.state())

        self.player.play()
    def pauseVideo(self): ########=========修改为点暂停按钮就是启动和暂停功能.
        if self.player.state() != 1: #====如果当前播放状态是精致.
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
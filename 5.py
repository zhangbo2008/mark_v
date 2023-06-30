class Ui_MainWindow(QMainWindow):
 
    def __init__(self):
        super(Ui_MainWindow, self).__init__()
        self.ui_init()
 
    def ui_init(self):
        self.resize(320, 250)
        self.main_widget = QWidget()  # 创建窗口主部件
        self.main_widget.setObjectName("main_widget")
        self.main_layout = QGridLayout()  # 创建主部件的网格布局
        self.main_widget.setLayout(self.main_layout)  # 设置窗口主部件布局为网格布局
 
        self.centralwidget = QWidget()
        self.centralwidget.setObjectName("centralwidget")  # 设置核心部件
        self.main_layout.addWidget(self.centralwidget)
        self.setCentralWidget(self.main_widget)  # 设置中心窗口setCentralWidget
        self.vbox = QVBoxLayout(self.centralwidget)
        self.setObjectName("vbox")
 
        self.topUi()
        self.playUi()
        self.barUi()
        self.bottomUi()
        self.retranslateUi()
        self.show()
 
    def topUi(self):
        self.top_btn = QPushButton()
        self.top_btn.setMaximumSize(QSize(200, 16777215))
        self.setObjectName("top_btn")
        self.top_label = QLabel()
        self.top_label.setMaximumSize(QSize(16777215, 10))
        self.top_label.setObjectName("top_label")
        self.top_hbox = QHBoxLayout()
        self.top_hbox.setObjectName("top_hbox")
        self.top_hbox.addWidget(self.top_btn)
        self.top_hbox.addWidget(self.top_label)
        self.vbox.addLayout(self.top_hbox)
 
 
    def playUi(self):
        self.groupBox = QGroupBox()
        self.groupBox.setObjectName("groupBox")
        self.gridLayout = QGridLayout(self.groupBox)
        self.setObjectName("gridLayout")
        # myVideoWidget重写QVideoWidget ，实现双击视频最大化
        self.widget = myVideoWidget()
        self.widget.setMaximumSize(QSize(16777215, 16777215))
        self.widget.setObjectName("widget")
        self.label = QLabel(self)
        self.label.setMaximumSize(QSize(16777215, 16777215))
        self.gridLayout.addWidget(self.label, 0, 0, 1, 1)
 
        self.vbox.addWidget(self.groupBox)
 
 
    def barUi(self):
        self.bar_hbox = QHBoxLayout()
        self.bar_hbox.setObjectName("bar_hbox")
        # CustomSlider 重写QSlider方法，实现拖动点击
        self.bar_slider = CustomSlider()
        self.bar_slider.setEnabled(False)   # 禁用
        self.bar_slider.setOrientation(Qt.Horizontal)
        self.bar_slider.setObjectName("bar_slider")
        self.bar_label = QLabel(self)
        self.bar_label.setMaximumSize(QSize(50, 10))
        self.bar_label.setObjectName("bar_label")
        self.bar_hbox.addWidget(self.bar_slider)
        self.bar_hbox.addWidget(self.bar_label)
 
        self.vbox.addLayout(self.bar_hbox)
 
    def bottomUi(self):
        self.bottom_hbox = QHBoxLayout()
        self.bottom_hbox.setObjectName("bottom_hbox")
        self.stop_btn = QPushButton()
        self.stop_btn.setObjectName("stop_btn")
        self.end_btn = QPushButton()
        self.end_btn.setObjectName("end_btn")
        spacerItem = QSpacerItem(40, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)
        self.bottom_hbox.addItem(spacerItem)
        self.bottom_hbox.addWidget(self.stop_btn)
        self.bottom_hbox.addItem(spacerItem)
        self.bottom_hbox.addWidget(self.end_btn)
        self.bottom_hbox.addItem(spacerItem)
 
        self.vbox.addLayout(self.bottom_hbox)
 
 
    def retranslateUi(self):
        _translate = QCoreApplication.translate # QCoreApplication会构建出当前线程需要的事件驱动器
        self.setWindowTitle(_translate("main_widget", "播放器   开发者: hp"))
        self.top_btn.setText(_translate("main_widget", "打开文件"))
        self.top_label.setText(_translate("main_widget", ""))
        self.groupBox.setTitle(_translate("main_widget", "预览"))
        self.label.setText(_translate("main_widget", "Waiting for video..."))
        self.bar_label.setText(_translate("main_widget", "00:00:00"))
        self.stop_btn.setText(_translate("main_widget", "暂停"))
        self.end_btn.setText(_translate("main_widget", "结束"))

class MainFunction(Ui_MainWindow):
 
    def __init__(self):
        super(MainFunction, self).__init__()
        self.play_flag = False  # 播放暂停的标志
        self.videoFullScreen = False # 判断当前widget是否全屏
        self.timer = QTimer()      # 定义定时器
        self.maxValue = 1000       # 设置进度条的最大值
        self.trigger()  # 触发方法
    def trigger(self):
        # 定义player
        self.player = QMediaPlayer()
        self.player.setVideoOutput(self.widget)
        self.top_btn.clicked.connect(self.openVideoFile)
        self.stop_btn.clicked.connect(self.playVideo)
        self.end_btn.clicked.connect(self.stopVideo)
        self.bar_slider.sliderMoved.connect(self.slider_progress_moved)
        self.bar_slider.sliderReleased.connect(self.slider_progress_released)
        self.bar_slider.customSliderClicked.connect(self.slider_progress_clicked)
    def openVideoFile(self):
        self.player.setMedia(QMediaContent(QFileDialog.getOpenFileUrl()[0]))  # 选取视频文件
        self.gridLayout.addWidget(self.widget, 0, 0, 1, 1)
        self.bar_slider.setEnabled(True)
        self.bar_slider.setRange(0,self.maxValue)
        self.player.play()  # 播放视频
        self.FLAG_PLAY = True
        self.timer.setInterval(1000)
        self.timer.start()
        self.timer.timeout.connect(self.onTimerOut)
    def onTimerOut(self):
        self.bar_slider.setValue(round(self.player.position()*self.maxValue/self.player.duration()))
        m, s = divmod(self.player.position() / 1000, 60)
        h, m = divmod(m, 60)
        self.bar_label.setText("%02d:%02d:%02d" % (h, m, s))
        self.widget.doubleClickedItem.connect(self.videoDoubleClicked)
class CustomSlider(QSlider):
    customSliderClicked = pyqtSignal(str)
    def __init__(self,parent=None):
        super(QSlider, self).__init__(parent)
    def mousePressEvent(self,QMouseEvent):
        super().mousePressEvent(QMouseEvent)    
        pos = QMouseEvent.pos().x() / self.width()
        self.setValue(round(pos*(self.maximum()-self.minimum())+self.minimum()))
        self.customSliderClicked.emit("mouse Press")
        self.bar_slider.sliderMoved.connect(self.slider_progress_moved)
        self.bar_slider.sliderReleased.connect(self.slider_progress_released)
        self.bar_slider.customSliderClicked.connect(self.slider_progress_clicked)
    def slider_progress_moved(self):
        self.timer.stop()
        self.player.setPosition(round(self.bar_slider.value() * self.player.duration() / self.maxValue))
    def slider_progress_clicked(self):
        self.player.setPosition(round(self.bar_slider.value() * self.player.duration() / self.maxValue))
MainFunction()
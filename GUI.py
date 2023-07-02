# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'GUI.ui'
#
# Created by: PyQt5 UI code generator 5.6
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(615, 404)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.gridLayout = QtWidgets.QGridLayout(self.centralwidget)
        self.gridLayout.setObjectName("gridLayout")
        self.wgt_video = myVideoWidget(self.centralwidget)
        self.wgt_video.setMinimumSize(QtCore.QSize(410, 200))
        self.wgt_video.setMaximumSize(QtCore.QSize(16777215, 16777215))
        palette = QtGui.QPalette()
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Active, QtGui.QPalette.Base, brush)
        brush = QtGui.QBrush(QtGui.QColor(0, 0, 0))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Active, QtGui.QPalette.Window, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Inactive, QtGui.QPalette.Base, brush)
        brush = QtGui.QBrush(QtGui.QColor(0, 0, 0))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Inactive, QtGui.QPalette.Window, brush)
        brush = QtGui.QBrush(QtGui.QColor(0, 0, 0))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Disabled, QtGui.QPalette.Base, brush)
        brush = QtGui.QBrush(QtGui.QColor(0, 0, 0))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Disabled, QtGui.QPalette.Window, brush)
        self.wgt_video.setPalette(palette)
        self.wgt_video.setAutoFillBackground(True)
        self.wgt_video.setObjectName("wgt_video")
        self.gridLayout.addWidget(self.wgt_video, 0, 0, 1, 1)
        self.sld_video = myVideoSlider(self.centralwidget)
        self.sld_video.setMinimumSize(QtCore.QSize(410, 0))
        self.sld_video.setMaximumSize(QtCore.QSize(16777215, 20))
        self.sld_video.setMaximum(100)
        self.sld_video.setOrientation(QtCore.Qt.Horizontal)
        self.sld_video.setObjectName("sld_video")
        self.gridLayout.addWidget(self.sld_video, 1, 0, 1, 1)
        self.lab_video = QtWidgets.QLabel(self.centralwidget)
        self.lab_video.setMaximumSize(QtCore.QSize(16777215, 50))
        self.lab_video.setObjectName("lab_video")
        self.gridLayout.addWidget(self.lab_video, 1, 1, 1, 1)#==============这个是最右边的那个进度条百分比数值!
        self.splitter = QtWidgets.QSplitter(self.centralwidget)
        self.splitter.setOrientation(QtCore.Qt.Horizontal)
        self.splitter.setObjectName("splitter")
        self.btn_open = QtWidgets.QPushButton(self.splitter)
        self.btn_open.setMaximumSize(QtCore.QSize(200, 250))
        self.btn_open.setObjectName("btn_open")
        self.btn_play = QtWidgets.QPushButton(self.splitter)
        self.btn_play.setMaximumSize(QtCore.QSize(200, 250))
        self.btn_play.setObjectName("btn_play")
        self.btn_stop = QtWidgets.QPushButton(self.splitter)
        self.btn_stop.setMaximumSize(QtCore.QSize(200, 250))
        self.btn_stop.setObjectName("btn_stop")
        self.sld_audio = QtWidgets.QSlider(self.splitter)
        self.sld_audio.setMinimumSize(QtCore.QSize(100, 0))
        self.sld_audio.setMaximumSize(QtCore.QSize(150, 20))
        self.sld_audio.setProperty("value", 99)
        self.sld_audio.setOrientation(QtCore.Qt.Horizontal)
        self.sld_audio.setObjectName("sld_audio")
        self.lab_audio = QtWidgets.QLabel(self.splitter)
        self.lab_audio.setObjectName("lab_audio")
        self.btn_cast = QtWidgets.QPushButton(self.splitter)
        self.btn_cast.setObjectName("btn_cast")
        self.gridLayout.addWidget(self.splitter, 2, 0, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 615, 23))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.lab_video.setText(_translate("MainWindow", "0%"))
        self.btn_open.setText(_translate("MainWindow", "open file"))
        self.btn_play.setText(_translate("MainWindow", "play"))
        self.btn_stop.setText(_translate("MainWindow", "pause"))
        self.lab_audio.setText(_translate("MainWindow", "volume:100%"))
        self.btn_cast.setText(_translate("MainWindow", "截图"))

from myVideoWidget import myVideoWidget
from myvideoslider import myVideoSlider

from PyQt5.QtCore import *
from PyQt5.QtWidgets import QSlider
import PyQt5
class myVideoSlider(QSlider):
    ClickedValue = pyqtSignal(int) #把时间mousepressevent, 绑定到clickedvalue上. 然后我们住函数再把clickedvalue发送后的效果函数设置为,player更新为新的索引位置.
    ClickedValue2 = pyqtSignal(int) #把时间mousepressevent, 绑定到clickedvalue上. 然后我们住函数再把clickedvalue发送后的效果函数设置为,player更新为新的索引位置.

    def __init__(self, father):
        super().__init__(Qt.Horizontal, father)

    def mousePressEvent(self, QMouseEvent):     #单击事件
        super().mousePressEvent(QMouseEvent)
        # print('鼠标事件的重写')
        value = QMouseEvent.localPos().x()
        # self.setValue(int(value)/9)
        print(value,33333333333333)
        # print(self.maximum(),33333333333333333333333333)
        value = round(value / self.width() * self.maximum())  # 根据鼠标点击的位置和slider的长度算出百分比
        # print('鼠标发送',value)
        self.ClickedValue.emit(value)

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
    if 0:
     def keyPressEvent(self, QKeyEvent):
        # print('触发前的位置',self.value())
        # print('')
        super().keyPressEvent(QKeyEvent)
        # print(1111111)
        # print(1)
        # print('按键的重写.....')
        # self.value()
        # # print('打印当前滑块位置',self.value())
        # # print()
        # value = self.value()
        # # self.setValue(int(value)/9)
        # # print(self.maximum(),33333333333333333333333333)
        # # value = round(value/self.width())  # 根据鼠标点击的位置和slider的长度算出百分比
        self.ClickedValue2.emit(self.value())

        # print('触发后的位置',self.value())












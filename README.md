'''
加入空格支持, press space to  play/pause the video.

updated to py_player_demo6.py
you can control the slider_time by right_arrow of keyboard(forward 1/1000 of the movie), left_arrow, page_up(forward 5/1000 of the movie), pagedown.



#最新版本py_player_demo5.Py
1. 如果打开后视频播放不对, 就安装根目录下的LAVFilters-0.77.2-Installer.exe
2.使用方法: 
    打开之后,拖动timeline,点击添加到左key, 添加到右key即可.记录高光时刻的起始millisecond和结束millisecond.
    最后点击保存到txt即可.
    

Notebly: In pyQt5, the video length 's unit is millisecond= 0.001 second
English version Readme:
1. if you find error with video player, just install the LAVFilters-0.77.2-Installer.exe  in the repos root directory.
2. using method:
    open the py_player_demo5.py , drag the timeline to the key millisecond you want annotate, press the add to left key , add to right key. meaning the begin and end of the hightlight of the video.  Last: press save to out.txt. 

为了网上大家都能用,把界面语言改成了英语.

界面战士:



![image](%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230702152846.png)



参考项目:
# PyQt_Video_Demo
This is a demo of using PyQt to design a simple video player
Detail description is in my blog https://blog.csdn.net/u012552296/article/details/89295273



使用pyqt自带的widget实现的简单视频播放的代码
详细过程在博客：https://blog.csdn.net/u012552296/article/details/89295273

simple video player result:
![GUI of vidow player](https://github.com/taroshi/PyQt_Video_Demo/blob/master/result.png)
#
'''







python 打包.


nuitka --standalone --windows-disable-console --mingw64 --nofollow-imports --show-memory --show-progress --plugin-enable=qt-plugins --include-qt-plugins=sensible,styles --follow-import-to=need --output-dir=o py_player_demo6.py

import tkinter as tk
import vlc
class VideoPlayer(tk.Frame):
    def __init__(self, parent):
        tk.Frame.__init__(self, parent)
        self.parent = parent
        self.parent.title("Video Player")
        self.parent.geometry("800x600")
        self.Instance = vlc.Instance('--no-xlib')
        self.player = self.Instance.media_player_new()  # 创建控制界面 
        self.create_widgets()
    def create_widgets(self):  # 播放按钮 
        self.play_button = tk.Button(self.parent, text="Play", command=self.play)
        self.play_button.pack(side="left")
    self.pause_button = tk.Button(self.parent, text="Pause", command=self.pause)
    self.pause_button.pack(side="left")  # 停止按钮 
    self.stop_button = tk.Button(self.parent, text="Stop", command=self.stop)
    self.stop_button.pack(side="left")  # 音量调节 
    self.volume_slider = tk.Scale(self.parent, orient="horizontal", command=self.set_volume, from_=0, to=100)
    self.volume_slider.set(50)
    self.volume_slider.pack(side="r
    self.fullscreen_button=tk.Button(self.parent, text="Fullscreen", command=self.toggle_fullscreen)
    self.fullscreen_button.pack(side="right")  # 视频画面 
    self.player_frame=tk.Frame(self.parent, bg="black")
    self.player_frame.pack(fill="both", expand=True)
    self.player.set_xwindow(self.player_frame.winfo_id())
    def open_file(self): file_path = tk.filedialog.askopenfilename() if file_path != '': me
    
def play(self): if self.player.get_state() == vlc.State.Ended: self.player.stop() self.player.play() def pause(self): self.player.pause() def stop(self): self.player.stop() def set_volume(self, val): self.player.audio_set_volume(int(val)) def toggle_fullscreen(self): self.parent.attributes("-fullscreen", True)
if __name__ == '__main__':
    root = tk.Tk()
    player = Video
    player.mainloop()
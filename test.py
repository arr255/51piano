#导入tkinter
from tkinter import *
import serial;
ser=serial.Serial('COM3',4800)
#键值对照表
muzeMap={'0':'0','1':'1','2':'2','3':'3','4':'4','5':'5','6':'6','7':'7',\
         'q':'a','w':'b','e':'c','r':'d','t':'e','y':'f','u':'g',\
         'a':'h','s':'i','d':'j','f':'k','g':'l','h':'m','j':'n','z':'z'}
#定义的方法 监听键盘事件
def printkey(event):
    if event.char in muzeMap:
        print('你按下了: ' + event.char)
        ser.write(muzeMap[event.char].encode());
#实例化tk
root = Tk()
root.title("键盘钢琴")
root.geometry("200x100")
label=Label(root,text="请输入音符")
label.pack();
label=Label(root,text="z键停止弹奏")
label.pack();
#实例化一个输入框
entry = Entry(root)
#给输入框绑定按键监听事件<Key>为监听任何按键 <Key-x>监听其它键盘，如大写的A<Key-A>、回车<Key-Return>
entry.bind('<Key>', printkey)
#显示窗体
entry.pack()
root.mainloop()
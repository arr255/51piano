# 键盘钢琴
## 环境配置
- python3 环境
- seriral<br>
 ```pip install pyserial```
- tkinter
- keil IDE
## 硬件设备
- 51 单片机
- 无源蜂鸣器

## 参数设定
在<kbd>test.py</kbd>中修改串口号，波特率等参数,默认端口COM3、波特率4800bps</br>
在单片机项目工程中修改波特率、输出端口等参数,默认波特率为4800bps、输出端口P1.6</br>
## 运行方式
在工作目录下</br>
``` python test.py ```

## 使用方式
- 根据设定的参数连接电路
- 在窗口中输入音符，1-7代表低音1-7；qwertyu分别代表中音1-7；asdfghj分别代表高音1-7;

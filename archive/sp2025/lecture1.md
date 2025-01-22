# Lecture 1

(注：下文中C指代ctrl，F指代fn，W指代windows，A指代alt)

## 课前准备
0.如果你使用的是苹果电脑，你可以跳过课前准备步骤。macOS和Linux之间的关系详见“UNIX史话”一节。

1. W-r，输入powershell  
2.依次键入以下指令安装WSL2  
```Powershell
wsl --install --no-distribution
wsl --set-default-version 2
```

3.通过Microsoft Store安装Ubuntu-24.04 LTS

4.在弹窗中输入用户名与用户密码，一般我习惯自用机直接用分发版的名称进行命名，比如用户名ubuntu，密码也是ubuntu

> 不要在这时关闭弹窗！如果关闭了请在Powershell中使用命令``wsl --unregister Ubuntu-24.04``
并回到第二步重新安装！


5.键入以下命令将Ubuntu-24.04导出到D盘  
```Powershell
wsl --export Ubuntu-24.04 D:\Ubuntu2404.tar
wsl --import Ubuntu-24.04 D:\WSL\Ubuntu2404 D:\Ubuntu2404.tar --version 2
```

6.这时Ubuntu中默认以root进行登录，将默认用户改为之前你所设置的用户
```Powershell
Ubuntu2404 config --default-user ubuntu
```

> 说实话，WSL的安装算是Linux各种载体中最为简便的一种了。如果你在上述步骤卡住了请及时求助，不要放弃并选择下载某个配好的Linux镜像绕路，你应当拥有使用纯净、由你定制的Linux Distro的权力！

## Hello, Linux!

### 初见
当你输入
```Powershell
wsl -d Ubuntu-24.04
```
之后，你便进入了Linux。对，你只需要命令行，也就是Linux Shell就能和Linux进行互动了。  
无论什么系统，你大概率都会问出一个问题：<br>我的XXX文件在哪儿？</br>一个Windows用户的回答大概率会以磁盘的某个分区，比如“C盘”或者“D盘”开头，每当切换到一个子文件夹的时候就要使用``\``分割。比如：
```
C:\Users\Lenovo\Applications\DevCpp
```
> 磁盘分区真的有必要吗？

文件夹在英文中为document，而目录在英文中为directory，前者在Windows中更加常用，后者在Linux中更为常用。在后文中我将混用两种表达。

Linux使用一种截然不同的方式进行路径标记，在Linux中有四个特殊的目录：``/``表示根目录，``~``表示用户主目录，``..``是上一级目录，``.``是目前所在的目录。每当切换到一个子目录时使用``/``分割。  

比如刚才那个文件的路径就应该表示为：
```
/mnt/c/Users/Lenovo/Applications/DevCpp
```

mnt是什么？一会儿讲到WSL底层原理的时候再说。  
``cd``(change directory)可以用来切换目录，在命令行输入
```shell
cd ~
```
就可以前往用户主目录。同理，这时
```shell
cd ..
```
可以前往/home，
```shell
cd .
```
不会发生变化，因为``.``代表目前所在的目录。  
> 当你不知道现在自己在哪儿的时候，使用``pwd``查看当前的目录

回来，
```shell
cd /mnt/d
```

### everything is a file
> In Linux, everything is a file.

file，中文译为文件。如果你问AI在Linux中文件是什么，它大概率会给你扯inode和块指针一类你听也听不懂的名词。我们不在乎那些，我们在乎的是“文件”的抽象为我们提供了一套统一的操作：查看文件，创造文件，打开文件，读文件，写文件，执行文件，关闭乃至删除文件。  

查看有什么文件和目录: ``ls <path>``  
创建目录: ``mkdir <dir_name>``  
创造文件: ``touch <filename>``  
读文件（查看文件内容）: ``cat <filename>``  
执行文件: ``./<filename>``
删除目录: ``rmdir <dir_name>``
删除文件: ``rm <filename>``

> rmdir只能用于删除空目录，如果目录中有内容则应当使用有参数的rm

> 注意，这里的执行文件前面必须加``./``，否则系统默认这个被执行的文件在``/bin``目录下  

> rm的操作是不可逆的，请在删除文件时仔细检查！

至于写文件，在Linux中内置了一个文本编辑器``nano``，你可以使用``nano <filename>``打开它。这个命令的默认行为是在当前路径下有这个文件的时候打开这个文件，如果没有就新建文件。好了，你已经学会nano了。  
还不信？使用方向键移动光标，剩下的操作方法都在最下头写着呢，顺带一提，有些表示方法中会用``^``代表Ctrl键  

### 帮手们

你可能这时候会想：同样的操作我在Windows上用鼠标右键也能干啊，还真干不成，因为右键菜单并没有为你提供更多的选项。当你使用右键的时候，你得跟着图形界面固有的逻辑走，它给你提供什么功能你就只能使用什么功能。命令行比你想象的强大。  

### tab
现在有一个叫``ThisIsAVeryLongDirectoryName``的目录，你该怎么进入这个目录？不用把整个名称都打出来，你只要``cd T``，然后再按一次``tab``键，命令就会自动为你补全。如果按一下tab没反应，那就说明匹配这个开头的名称不止一个，敲两下看看可供你补全的选项。

### man和info
接下来是``man``和``info``，当你输入``man``的时候系统会提示你输入``man man``进行查看。（这里大致浏览提示并进行解释）ok，那我们应该输入``man ls``来查看ls相关的帮助文档。可以看到ls有一些可选参数。我们试试``ls -la``，以列表形式列出文件，不忽略.开头的文件。info也是同理的，你可以使用``info <name>``进行查看。

使用方向键在帮助文档中上下翻阅，使用q退出。当想要寻找特定内容时不妨试试``/<pattern_name>``进行查找，比如在``man ls``中查找递归列出文件的参数你就可以使用``/recu``进行查找，这个参数应该是-R  

你可以大致看出Linux的设计思路——每个工具只做一件事，但是绝对做好，做到极致。

> cd不是一个命令，man中也没有设置cd的相关信息。因为如果cd是一条命令，那么shell将产生一棵无穷递归的进程树（以后你学了操作系统就知道这句话是什么意思了）

### 停止命令的执行

```shell
sleep 1000
```
这时候你会怎么停下它，关掉这个终端再开一个？那可太不优雅了。Linux中有很多停止程序运行的方法：
<ul>
<li>C-c: 向前台程序发送SIGINT信号</li>
<li>C-z: 停止前台程序对应的进程</li>
<li>C-d: 发送信号杀死前台程序对应的进程</li>
</ul>

## 下载软件和包
(TODO)
### 从镜像源开始说起......
(TODO)
### Linux的用户策略
(TODO)
## 正确的方法
(TODO)
### 多查，多看，自己先试试
(TODO)
### 为什么你应该试试Linux？
(TODO)
### 我该选哪个Distro？
(TODO)
## UNIX史话
(TODO)
## 练习题

注：练习题顺序与难度无关，仅供娱乐！  

### Linux
(1)思考一下，磁盘分区真的有必要吗，为什么Windows时至今日都在保留磁盘分区这个设定？  
(2)在``man``中查看``printf``相关的内容  
(3)分别使用``tree``和``pstree``列出当前文件和当前进程  
(4)了解正则表达式相关的内容，尝试列出你的某个目录中以r开头以c结尾的文件  
(5)使用``lscpu``查看本机CPU和高速缓存相关的信息  
(6)使用``neofetch``，并将命令的输出结果发在课程群中装哔  
(7)尝试在VMware或者Oracle VirtualBox中安装Ubuntu或者Debian。如果你备份好了数据也可以尝试一下物理机安装  
(?)DANGER ZONE: 在explainshell（见实用链接一栏）中查找以下命令含义：
```shell
sudo rm -rf /*
sudo mv /* /dev
:(){ :|:& };:
```
（注：在实机上运行这些命令后果自负！！！）  

### 互联网

(1)许多教程会告诉你C-c用于强行退出程序。这种说法有什么不严谨之处？（提示：使用反证法）  
(2)白嫖2024年诺贝尔物理学奖得主之一Jeoffrey Hinton的论文（你总不想给Nature交一个月几十美金的会费吧）  
(3)在Google上查找正则表达式该如何使用  
(4)查一查google.com的域名及子域名（提示：先搜搜``Google Hacking``再下手）  
(5)使用ping查看主机是否能够与某个URL对应的服务器进行连接  
(6)查一查Markdown该怎么写  
(7)你知道D语言吗？它曾是第一个挑战C++地位的编程语言。大致了解一下它（你不用学，现在几乎没人用D了）  
(8)DuckDuckGo是近两年异军突起的一个搜索引擎，试着用一用它  
(9)Wolfram Alpha可以用来查询数学和自然科学相关的信息。请在Wolfram Alpha中解微分方程：``y'''y - yx = y''``  
(?)地狱难度：Overleaf是一个在线LaTeX集成开发环境，请在百度中寻找Overleaf官网  

## 拓展阅读

<a href="https://www.youtube.com/watch?v=tc4ROCJYbm0&t=1s">UNIX的官方介绍</a>  
<a href="https://www.bilibili.com/video/BV1U94y1a7CZ/?vd_source=8204d1a0fabafab989c42faaec9e4a8c">终端是什么？</a>  
<a href="https://dsf.berkeley.edu/cs262/unix.pdf">The UNIX Time-Sharing System</a>，UNIX领域最重要的论文之一  

## 实用链接
<a href="https://man7.org/linux/man-pages/index.html">man7.org</a>，在线的帮助文档，你可以使用C-f进行匹配查找  
<a href="https://explainshell.com/">explainshell</a>，可以用于直接查找命令的含义  
<a href="https://tldr.sh/">tldr</a>，太长了不想看？看看这个，直接复制粘贴就能使用的命令实例  

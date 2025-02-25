# 课前准备

(注：下文中C指代ctrl，F指代fn，W指代windows，A指代alt)

> 这是一个Markdown写成的讲义，你可以将它线上转化为pdf，或者使用``vscode``的Markdown侧边预览进行查看。如果你想获得更美观的视觉体验还可以试试<a href="https://marktext.weero.net/download/">MarkText</a>

时间：2月24日18:00，2月25日18:00  
地点：大活327

0.如果你使用的是苹果电脑，你可以跳过课前准备步骤。macOS和Linux之间的关系详见“UNIX史话”一节。

1.W-r，输入powershell  

2.依次键入以下指令安装WSL2  
```Powershell
wsl --install --no-distribution
wsl --set-default-version 2
```

3.通过Microsoft Store安装Ubuntu-24.04 LTS

4.在弹窗中输入用户名与用户密码，一般我习惯自用机直接用分发版的名称进行命名，比如用户名ubuntu，密码也是ubuntu，然后稍等片刻，在弹窗最下方出现一行以 ``$`` 结尾的字后关闭弹窗  

> 不要在出现 ``$`` 之前关闭弹窗！如果关闭了请在Powershell中使用命令 ``wsl --unregister Ubuntu-24.04`` 并回到第三步重新安装！


5.键入以下命令将Ubuntu-24.04导出到D盘  
```Powershell
wsl --export Ubuntu-24.04 D:\Ubuntu2404.tar
wsl --unregister Ubuntu-24.04
wsl --import Ubuntu-24.04 D:\Ubuntu2404 D:\Ubuntu2404.tar --version 2
```

6.这时Ubuntu中默认以root进行登录，将默认用户改为之前你所设置的用户
```Powershell
Ubuntu2404 config --default-user ubuntu
```

7.在``C:\用户\<用户名>\``处新建文本文档，更名为``.wslconfig``，使用记事本打开，输入以下内容并保存  
```
[wsl2]
networkingMode=mirrored
```
这样WSL就可以使用本机的代理网络了

> 说实话，WSL的安装算是Linux各种载体中最为简便的一种了。如果你在上述步骤卡住了请及时求助，不要放弃并选择下载某个配好的Linux镜像绕路，你应当拥有使用纯净、由你定制的Linux Distro的权力！

> 你还可以尝试在VMware或者Oracle VirtualBox中安装Linux虚拟机，或者如果你备份好了文件也可以尝试安装物理机Linux。我们把它设置为了一道练习题，你可以课后试试！
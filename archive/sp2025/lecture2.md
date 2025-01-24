# Lecture 2

(注：下文中C指代ctrl，F指代fn，W指代windows，A指代alt)  

> 这是一个Markdown写成的讲义，你可以将它线上转化为pdf，或者使用``vscode``的Markdown侧边预览进行查看。如果你想获得更美观的视觉体验还可以试试<a href="https://marktext.weero.net/download/">MarkText</a>

## 课前准备

```shell
sudo apt install vim gcc valgrind gdb 
```

## 引子

那是第十一周的周一，早间10:05，你在M楼的XXX教室。  
你还在纠结于上周三没搞明白的行指针和指针数组。  
老师已经讲起来了链表，好快啊，你没听懂。  
快下课了，老师让你们几人一组，做个学生成绩管理系统。  
地狱般的时光开始了，你不会debug，甚至开始了自我怀疑。  
你觉得C弱爆了，为什么我还要手动管理内存，为什么我的数组不能变长？  

那如果我告诉你，Linux其实就是一个硕大无比的C程序，你会怎么想？  
你应该了解C，哪怕你以后不用它。  

## vim

nano并不是一个把快捷键用到炉火纯青的编辑器，还有比它更狠的，那就是它的祖师爷vim  
你可以和nano一样，用``vim hello.c``打开一个文件，或者在这个文件不存在的时候创造这个文件。打开之后，你处于vim的浏览模式  
```
命令模式
   ^| esc
  :|V
浏览模式 <-你现在在这儿
   ^| i
esc|V
编辑模式
```
使用``i``进入编辑模式，键入以下程序：
```C
#include<stdio.h>
int main()
{
    printf("Hello(again), C!\n");
    return 0;
}
```  
使用``esc``回到浏览模式，使用``h`` ``j`` ``k`` ``l``进行光标的左、上、右、下方向的移动（j像一个向下的箭头，h和l分别在最左和最右，剩下一个k是向上）  
在浏览模式，你可以像在``man page``里一样使用``/``配合通配符进行查找，这个方法在大文件中很有用  
输入``:``，这时终端的左下角出现了一个冒号等待你，你可以先输入``w``，回车，这样你的改动就写入了``hello.c``，再输入``:``，键入``q``，这样你就退出了vim  
好了，你已经基本学会了vim的使用方法，可以用笨办法和vim进行交互了。你可以在课后空出半个小时，在命令行中键入``vimtutor``阅读一下，或者打印出vim的快捷键列表放在手头进行参考。

## Hello, world的一生

写完了，你应该找一个编译器将``hello.c``编译为可执行文件。你有两种选择，由GNU维护的gcc和由llvm维护的clang。gcc的使用范围更广一些。  
```shell
gcc hello.c
./a.out
```
你不好奇这中间发生了什么吗，不是说CPU只认识0和1吗？  

### 预处理器和宏

(TODO)

## debug

### valgrind

(TODO)

### gdb

(TODO)

## 大型工程的构建

### 头文件

(TODO)

### Makefile

(TODO)

## 练习题

### C

(1)(TODO)

### 互联网
(1)Hello和Hello(again)分别致敬了两场著名的科技发布会，你知道它们分别是谁吗？  
(2)  
(?)你察觉到了吗？我们熟知的计算机世界建立在“绝对可信”的代码之上。我们享受着“绝对可信”的软件并自由地使用它们。然而<a href="https://cve.mitre.org/cgi-bin/cvekey.cgi?keyword=linux">Linux内核bug</a>光2024年就产生了将近三千个，Windows更新后产生致命问题也不是什么新鲜事。哪怕是gdb，在某些刁钻的bug前还是会破功，报逃脱了层层错误处理之后还活下来的段错误。你对此有什么感想？

## 拓展阅读

<a href="https://www.bilibili.com/video/BV1qb4y1R7Z4/?spm_id_from=333.1387.favlist.content.click&vd_source=8204d1a0fabafab989c42faaec9e4a8c">什么是机器语言？</a>  
<a href="https://colorcomputerarchive.com/repo/Documents/Books/The%20C%20Programming%20Language%20%28Kernighan%20Ritchie%29.pdf">The C Programming Language</a> 确切来说这本书不只是C，更像是《如何在Ken Thompson出生之前手搓UNIX标准库的一个小部分》  
<a href="https://www.cs.sfu.ca/~ashriram/Courses/CS295/assets/books/CSAPP_2016.pdf">Computer Systems: A Programmer's Perspective</a> 借助C，了解计算机系统的全貌  
<a href="https://akaedu.github.io/book/index.html">Linux C一站式学习</a> 一本堪称仁至义尽的中文C教材  

## 实用链接

<a href="https://gcc.gnu.org/onlinedocs/">gcc online documentation</a>  
<a href="https://www.sourceware.org/gdb/documentation/">gdb documantation</a>  
<a href="https://resources.sei.cmu.edu/downloads/secure-coding/assets/sei-cert-c-coding-standard-2016-v01.pdf">CERT C Coding Standard</a> 怎么编写可靠的C程序？你需要它！  
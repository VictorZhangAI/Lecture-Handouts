# Lecture 2

(注：下文中C指代ctrl，F指代fn，W指代windows，A指代alt)  

> 这是一个Markdown写成的讲义，你可以将它线上转化为pdf，或者使用``vscode``的Markdown侧边预览进行查看。如果你想获得更美观的视觉体验还可以试试<a href="https://marktext.weero.net/download/">MarkText</a>

## 课前准备

```shell
sudo apt install vim gcc valgrind gdb 
```

## 引子

还记得我们第一节课中的提示吗？C本质上是UNIX的副产物。没有UNIX，我们对C的学习与认识就只能限制在一个抽象层上点点点。  
C程序是怎么变成可执行文件的，C还有什么不为我们所熟知的点？这些东西不在UNIX上操作是没办法讲清楚的。Let's make our hands dirty, enjoy hacking!  

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
当然，你还可以使用``-o``来重命名输出的可执行文件
```shell
gcc hello.c -o hello
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

### 不止是C

(1)emacs是另一个将快捷键使用到炉火纯青的编辑器，和vim不同，emacs追求极致的扩展性，甚至为了扩展性它的本体就要占据117MB的空间。如果有兴趣可以尝试以下emacs  
(2)  
(?)大型练习：你在大型项目中总有可能会有思路走偏或者bug藏在层层函数和抽象之后的情况。如果有那么一个软件可以帮助你回到最近的没出错的那一刻重新开发，那该多好！基于这个思想，版本管理系统诞生了。查找资料，了解git的使用方法。（我并不想在课上讲解git，很多时候git的命令乃至使用命令的顺序都是高度公式化的，如果我讲的话大概率也和念官方文档差不多）

### 互联网
(1)Hello和Hello(again)分别致敬了两场著名的科技发布会，你知道它们分别是谁吗？  
(2)在*The C Programming Language*中作者使用的编译器叫``cc``，但我们只知道``gcc``，当你在命令行中输入``which cc``和``which gcc``的时候出现了相同的结果。那么这两者之间有什么联系呢？  
(3)事实上``gcc``默认使用的C标准并不是我们所熟知的``ANSI C``，而是``GNU C``。在早期出版的*The C Programming Language*中使用的C标准是``K&R C``，这三者谁是谁的拓展，它们又和国际通用的``ISO C``标准之间有什么联系？``gcc``有什么flag可以使得你的代码使用``ANSI C``编译？  
(?)你察觉到了吗？我们熟知的计算机世界建立在“绝对可信”的代码之上。我们享受着“绝对可信”的软件并自由地使用它们。然而<a href="https://cve.mitre.org/cgi-bin/cvekey.cgi?keyword=linux">Linux内核bug</a>光2024年就产生了将近三千个，Windows更新后产生致命问题也不是什么新鲜事。哪怕是gdb，在某些刁钻的bug前还是会破功，出现逃脱了层层错误处理之后还活下来的段错误。你对此有什么感想？

## 拓展阅读

<a href="https://www.bilibili.com/video/BV1qb4y1R7Z4/?spm_id_from=333.1387.favlist.content.click&vd_source=8204d1a0fabafab989c42faaec9e4a8c">什么是机器语言？</a>  
<a href="https://colorcomputerarchive.com/repo/Documents/Books/The%20C%20Programming%20Language%20%28Kernighan%20Ritchie%29.pdf">The C Programming Language</a> 确切来说这本书不只是C，更像是《如何在Ken Thompson出生之前手搓UNIX标准库的一个小部分》  
<a href="https://www.cs.sfu.ca/~ashriram/Courses/CS295/assets/books/CSAPP_2016.pdf">Computer Systems: A Programmer's Perspective</a> 借助C，了解计算机系统的全貌  
<a href="https://akaedu.github.io/book/index.html">Linux C一站式学习</a> 一本堪称仁至义尽的中文C教材  

## 实用链接

<a href="https://gcc.gnu.org/onlinedocs/">gcc online documentation</a>  
<a href="https://www.sourceware.org/gdb/documentation/">gdb documantation</a>  
<a href="https://resources.sei.cmu.edu/downloads/secure-coding/assets/sei-cert-c-coding-standard-2016-v01.pdf">CERT C Coding Standard</a> 怎么编写可靠的C程序？你需要它！  
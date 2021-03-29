## 练习6.6

说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时达到这三种形式。

解：

形参定义在函数形参列表里面；局部变量定义在代码块里面； 局部静态变量在程序的执行路径第一次经过对象定义语句时初始化，并且直到程序终止时才被销毁。

## 练习6.9 : fact.cc | factMain.cc
编写你自己的fact.cc 和factMain.cc ，这两个文件都应该包含上一小节的练习中编写的 Chapter6.h 头文件。通过这些文件，理解你的编译器是如何支持分离式编译的。

```cpp
// fact.cc
#include "Chapter6.h"

int multi(int a, int b){
  return a * b;
}

// factMain.cc
#include "Chapter6.h"
#include <iostream>

int main(){
  std::cout << multi(2,3) << std::endl;
  return 0;
}

// Chapter6.h
int multi(int a, int b);
```

```
g++ fact.cc factMain.cc -o main
```

## 练习6.13
假设T是某种类型的名字，说明以下两个函数声明的区别： 一个是void f(T), 另一个是void f(&T)。

解：

void f(T)的参数通过值传递，在函数中T是实参的副本，改变T不会影响到原来的实参。 void f(&T)的参数通过引用传递，在函数中的T是实参的引用，T的改变也就是实参的改变。

## 练习6.15
说明find_char函数中的三个形参为什么是现在的类型，特别说明为什么s是常量引用而occurs是普通引用？ 为什么s和occurs是引用类型而c不是？ 如果令s是普通引用会发生什么情况？ 如果令occurs是常量引用会发生什么情况？

解：

 - 因为字符串可能很长，因此使用引用避免拷贝；
 - 而在函数中我们不希望改变s的内容，所以令s为常量。
 - occurs是要传到函数外部的变量，所以使用引用，occurs的值会改变，所以是普通引用。
 - 因为我们只需要c的值，这个实参可能是右值(右值实参无法用于引用形参)，所以c不能用引用类型。
 - 如果s是普通引用，也可能会意外改变原来字符串的内容。
 - occurs如果是常量引用，那么意味着不能改变它的值，那也就失去意义了。

## 练习6.19
假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。

double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
(a) calc(23.4, 55.1);
(b) count("abcda",'a');
(c) calc(66);
(d) sum(vec.begin(), vec.end(), 3.8);

解：

(a) 不合法。calc只有一个参数。
(b) 合法。
(c) 合法。
(d) 合法。

## 练习6.20

引用形参什么时候应该是常量引用？如果形参应该是常量引用，而我们将其设为了普通引用，会发生什么情况？

解：

应该尽量将引用形参设为常量引用，除非有明确的目的是为了改变这个引用变量。 如果形参应该是常量引用，而我们将其设为了普通引用，那么常量实参将无法作用于普通引用形参。

## 练习6.21
编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。 函数比较int的值和指针所指的值，返回较大的那个。 在该函数中指针的类型应该是什么？

解：

```cpp
#include <iostream>
using std::cout;

int larger_one(const int i, const int *const p)
{
    return (i > *p) ? i : *p;
}

int main()
{
    int i = 6;
    cout << larger_one(7, &i);

    return 0;
}
应该是const int *类型。
```

## 练习6.22

编写一个函数，令其交换两个int指针。

解：

```cpp
#include <iostream>
#include <string>

void swap(int*& lft, int*& rht)
{
    auto tmp = lft;
    lft = rht;
    rht = tmp;
}

int main()
{
    int i = 42, j = 99;
    auto lft = &i;
    auto rht = &j;
    swap(lft, rht);
    std::cout << *lft << " " << *rht << std::endl;

    return 0;
}
```

## 练习6.23

参考本节介绍的几个print函数，根据理解编写你自己的版本。 依次调用每个函数使其输入下面定义的i和j:

```int i = 0, j[2] = { 0, 1 };```

解：

```cpp
#include <iostream>
using std::cout; using std::endl; using std::begin; using std::end;

void print(const int *pi)
{
    if(pi)
        cout << *pi << endl;
}

void print(const char *p)
{
    if (p)
        while (*p) cout << *p++;
    cout << endl;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << endl;
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] << endl;
    }
}

void print(int (&arr)[2])
{
    for (auto i : arr)
        cout << i << endl;
}

int main()
{
    int i = 0, j[2] = { 0, 1 };
    char ch[5] = "pezy";
    
    print(ch);
    print(begin(j), end(j));
    print(&i);
    print(j, end(j)-begin(j));
    print(j);
    
    return 0;
}
```

## 练习6.24

描述下面这个函数的行为。如果代码中存在问题，请指出并改正。

```cpp
void print(const int ia[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}
```

解：

当数组作为实参的时候，会被自动转换为指向首元素的指针。 因此函数形参接受的是一个指针。 如果要让这个代码成功运行(不更改也可以运行），可以将形参改为数组的引用。

```cpp
void print(const int (&ia)[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}
```

## 练习6.26
编写一个程序，使其接受本节所示的选项；输出传递给main函数的实参内容。

解：

包括6.25

```cpp
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string str;
    for (int i = 1; i != argc; ++i)
        str += std::string(argv[i]) + " ";

    std::cout << str << std::endl;
    return 0;
}
```

## 练习6.29
在范围for循环中使用initializer_list对象时，应该将循环控制变量声明成引用类型吗？为什么？

解：

应该使用常量引用类型。initializer_list对象中的元素都是常量，我们无法修改initializer_list对象中的元素的值。
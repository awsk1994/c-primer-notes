## 练习2.1
类型 int、long、long long 和 short 的区别是什么？无符号类型(unsigned)和带符号类型(signed)的区别是什么？float 和 double的区别是什么？

解：

C++ 规定 short 和 int 至少16位，long 至少32位，long long 至少64位。 带符号类型(signed)能够表示正数、负数和 0 ，而无符号类型(unsigned)只能够表示 0 和正整数。

## 练习2.2
计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

解：

使用double。需要进行浮点计算。

## 练习2.3
读程序写结果。
```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

```
32
4 294 967 264 // explanation below
/* 
 - assume unsigned int32 => max number = 2^32-1 = 4 294 967 295
 - From 10 to 0, we need to minus 10.
 - From 0 to max_num, we need to minus 1.
 - We have 42-11=31 left, thus, the ans = max_num - 31 = 4 294 967 264
*/
32 
-32 // 10-42 = -32
0
0
```

## 练习2.5

指出下述字面值的数据类型并说明每一组内几种字面值的区别：

```
(a) 'a', L'a', "a", L"a"
(b) 10, 10u, 10L, 10uL, 012, 0xC
(c) 3.14, 3.14f, 3.14L
(d) 10, 10u, 10., 10e-2
```

解：

(a): 字符字面值，宽字符字面值，字符串字面值，宽字符串字面值。
(b): 十进制整型，十进制无符号整型，十进制长整型，long unsigned，八进制整型，十六进制整型。
(c): double, float, long double
(d): 十进制整型，十进制无符号整型，double, double

## 练习2.6
下面两组定义是否有区别，如果有，请叙述之：
```cpp
int month = 9, day = 7;
int month = 09, day = 07;
```

解：

第一行定义的是十进制的整型，第二行定义的是八进制的整型。但是month变量有误，八进制不能直接写9。

## 练习2.7
下述字面值表示何种含义？它们各自的数据类型是什么？
```
(a) "Who goes with F\145rgus?\012"
(b) 3.14e1L
(c) 1024f
(d) 3.14L
```

解：

(a) Who goes with Fergus?(换行)，string 类型
(b) long double
(c) 无效，因为后缀f只能用于浮点字面量，而1024是整型。
(d) long double

## 练习2.8
请利用转义序列编写一段程序，要求先输出 2M，然后转到新一行。修改程序使其先输出 2，然后输出制表符，再输出 M，最后转到新一行。

解：

```cpp
#include <iostream>
int main(){
  std::cout << 2 << "M\n" << std::endl;
  std::cout << 2 << "\tM\n" << std::endl;
  return 0;
}
```

## 练习2.9
解释下列定义的含义，对于非法的定义，请说明错在何处并将其改正。

(a) std::cin >> int input_value;

(b) int i = { 3.14 };

(c) double salary = wage = 9999.99;

(d) int i = 3.14;


解：

(a): 应该先定义再使用。
```cpp
int input_value = 0;
std::cin >> input_value;
```

(b): 用列表初始化内置类型的变量时，如果存在丢失信息的风险，则编译器将报错。
```cpp
double i = { 3.14 };
```

(c): 在这里wage是未定义的，应该在此之前将其定义。
```cpp
double wage;
double salary = wage = 9999.99;
```

(d): 不报错，但是小数部分会被截断。
```cpp
double i = 3.14;
```

## 练习2.10
下列变量的初值分别是什么？
```cpp
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}
```

解：

global_str和global_int是全局变量，所以初值分别为空字符串和0。 local_int是局部变量并且没有初始化，它的初值是未定义的。 local_str 是 string 类的对象，它的值由类确定，为空字符串。

## 练习2.11
指出下面的语句是声明还是定义：

(a) extern int ix = 1024;

(b) int iy;

(c) extern int iz;

解：

(a): 定义 

(b): 定义 

(c): 声明


## 练习2.12
请指出下面的名字中哪些是非法的？

(a) int double = 3.14;

(b) int _;

(c) int catch-22;

(d) int 1_or_2 = 1;

(e) double Double = 3.14;

解：

(a), (c), (d) 非法。 （not sure why d is though..?)

## 练习2.13
下面程序中j的值是多少？

```cpp
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```

解：

j的值是100，局部变量i覆盖了全局变量i。

## 练习2.14
下面的程序合法吗？如果合法，它将输出什么？
```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
    sum += i;
std::cout << i << " " << sum << std::endl;
```

解：

合法。输出是 100 45 。

## 练习2.15
下面的哪个定义是不合法的？为什么？
```
(a) int ival = 1.01;
(b) int &rval1 = 1.01;
(c) int &rval2 = ival;
(d) int &rval3;
```

解：

(b)和(d)不合法，(b)引用必须绑定在对象上，(d)引用必须初始化。

## 练习2.16
考察下面的所有赋值然后回答：哪些赋值是不合法的？为什么？哪些赋值是合法的？它们执行了哪些操作？
```
int i = 0, &r1 = i; 
double d = 0, &r2 = d;
(a) r2 = 3.14159;
(b) r2 = r1;
(c) i = r2;
(d) r1 = d;
```

解：

(a): 合法。给 d 赋值为 3.14159。
(b): 合法。会执行自动转换（int->double）。
(c): 合法。会发生小数截取。
(d): 合法。会发生小数截取。

## 练习2.17
执行下面的代码段将输出什么结果？
```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

解：

输出：10, 10

## 练习2.18

编写代码分别改变指针的值以及指针所指对象的值。

解：

```cpp
#include <iostream>

int main(){
  int a = 1, b = 2, *p = &a;

  std::cout << *p << std::endl;

  *p = 10;  // 更改指针所指对象的值
  std::cout << "p = " << *p << std::endl;

  p = &b; // 更改指针的值指向b
  std::cout << "p = " << *p << std::endl;
}
```

## 练习2.19

说明指针和引用的主要区别

解：

引用是另一个对象的别名，而指针本身就是一个对象。 引用必须初始化，并且一旦定义了引用就无法再绑定到其他对象。而指针无须在定义时赋初值，也可以重新赋值让其指向其他对象。

## 练习2.20
请叙述下面这段代码的作用。

```cpp
int i = 42;
int *p1 = &i; 
*p1 = *p1 * *p1;
```

解：

让指针 pi 指向 i，然后将 i 的值重新赋值为 42 * 42 (1764)。

## 练习2.21

请解释下述定义。在这些定义中有非法的吗？如果有，为什么？

```cpp
int i = 0;
```

(a) double* dp = &i;

(b) int *ip = i;

(c) int *p = &i;

解：

(a): 非法。不能将一个指向 double 的指针指向 int 。

(b): 非法。不能将 int 变量赋给指针。

(c): 合法。

## 练习2.22

假设 p 是一个 int 型指针，请说明下述代码的含义。

```cpp
if (p) // ...
if (*p) // ...
```

解：

第一句判断 p 是不是一个空指针, 第二句判断 p 所指向的对象的值是不是为0

## 练习2.23

给定指针 p，你能知道它是否指向了一个合法的对象吗？如果能，叙述判断的思路；如果不能，也请说明原因。

解：

不能，因为首先要确定这个指针是不是合法的，才能判断它所指向的对象是不是合法的。**(??)**

(https://blog.csdn.net/pengrui18/article/details/90291934)

 - 答案1：这个问题我的思路是：首先用*p将其值输出来，如果编译器报错，证明p指向一个无效的对象，要么p=0要么p未进行初始化，此时可以用if(p == NULL)进行判断即可，不知道大家是否有好的思路噻。。。
 - 答案2：问的是有效对象，必然是不能确定。
 - 答案3：C++ 无法检测指针是否未被初始化，也无法区分一个地址是有效地址，还是有指针所分配的存储空间中存放的不确定的二进制位形成的地址。
 - 觉得这里还是围绕一个模糊的概念，到底指针的地址是否有效，比如int *p =0; p = 10;那么指针p肯定是一个不合法的对象，所以我还是比较支持第二种答案（纯属个人意见），欢迎广大网友前来讨论。

## 练习2.25
说明下列变量的类型和值。

(a) int* ip, i, &r = i;

(b) int i, *ip = 0;

(c) int* ip, ip2;

解：

(a): ip 是一个指向 int 的指针, i 是一个 int, r 是 i 的引用。

(b): i 是 int , ip 是一个空指针。

(c): ip 是一个指向 int 的指针, ip2 是一个 int。

## 练习2.26

下面哪些语句是合法的？如果不合法，请说明为什么？

解：

```cpp
const int buf;      // 不合法, const 对象必须初始化
int cnt = 0;        // 合法
const int sz = cnt; // 合法
++cnt; ++sz;        // 不合法, const 对象不能被改变
```
## 练习2.27

下面的哪些初始化是合法的？请说明原因。

解：

```cpp
int i = -1, &r = 0;         // 不合法, r 必须引用一个对象
int *const p2 = &i2;        // 合法，常量指针
const int i = -1, &r = 0;   // 合法
const int *const p3 = &i2;  // 合法
const int *p1 = &i2;        // 合法
const int &const r2;        // 不合法, r2 是引用，引用没有顶层 const
const int i2 = i, &r = i;   // 合法
```

## 练习2.28
说明下面的这些定义是什么意思，挑出其中不合法的。

解：

```cpp
int i, *const cp;       // 不合法, const 指针必须初始化
int *p1, *const p2;     // 不合法, const 指针必须初始化
const int ic, &r = ic;  // 不合法, const int 必须初始化
const int *const p3;    // 不合法, const 指针必须初始化
const int *p;           // 合法. 一个指针，指向 const int
```

## 练习2.29

假设已有上一个练习中定义的那些变量，则下面的哪些语句是合法的？请说明原因。

解：

```cpp
i = ic;     // 合法, 常量赋值给普通变量
p1 = p3;    // 不合法, p3 是const指针不能赋值给普通指针
p1 = &ic;   // 不合法, 普通指针不能指向常量
p3 = &ic;   // 合法, p3 是常量指针且指向常量
p2 = p1;    // 合法, 可以将普通指针赋值给常量指针
ic = *p3;   // 合法, 对 p3 取值后是一个 int 然后赋值给 ic
```

## 练习2.30

对于下面的这些语句，请说明对象被声明成了顶层const还是底层const？

```cpp
const int v2 = 0; int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```

解：

v2 是顶层const，p2 是底层const，p3 既是顶层const又是底层const，r2 是底层const。

## 练习2.31 (!!! need to study this again...)

假设已有上一个练习中所做的那些声明，则下面的哪些语句是合法的？请说明顶层const和底层const在每个例子中有何体现。

解：

```cpp
r1 = v2; // 合法, 顶层const在拷贝时不受影响
p1 = p2; // 不合法, p2 是底层const，如果要拷贝必须要求 p1 也是底层const
p2 = p1; // 合法, int* 可以转换成const int*
p1 = p3; // 不合法, p3 是一个底层const，p1 不是
p2 = p3; // 合法, p2 和 p3 都是底层const，拷贝时忽略掉顶层const
```

## 练习2.32

下面的代码是否合法？如果非法，请设法将其修改正确。

``int null = 0, *p = null;``

解：

合法。指针可以初始化为 0 表示为空指针。

## 练习2.33

利用本节定义的变量，判断下列语句的运行结果。

解：

```cpp
a=42; // a 是 int
b=42; // b 是一个 int,(ci的顶层const在拷贝时被忽略掉了)
c=42; // c 也是一个int
d=42; // d 是一个 int *,所以语句非法
e=42; // e 是一个 const int *, 所以语句非法
g=42; // g 是一个 const int 的引用，引用都是底层const，所以不能被赋值
```

## 练习2.35

判断下列定义推断出的类型是什么，然后编写程序进行验证。


```cpp
const int i = 42;
auto j = i; const auto &k = i; auto *p = &i; 
const auto j2 = i, &k2 = i;
```

解：

```
j 是 int // auto一般忽略掉顶层const
k 是 const int的引用 // const已被定义了，auto只好是const int 引用
p 是const int * // p是指向i的指针，由于i是const int，因此p是指向const int的指针
j2 是const int // 已经定义了const，所以一定是const int
k2 是 const int 的引用。 // 引用不会忽略掉顶层const，因此是const int引用
```




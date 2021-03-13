## 练习4.2

根据4.12节中的表，在下述表达式的合理位置添加括号，使得添加括号后运算对象的组合顺序与添加括号前一致。 (a) *vec.begin() (b) *vec.begin() + 1

解：

```
*(vec.begin())
(*(vec.begin())) + 1
```

## 练习4.9

解释在下面的if语句中条件部分的判断过程。

```cpp
const char *cp = "Hello World";
if (cp && *cp)
```

解：

 - 首先判断cp，cp 不是一个空指针，因此cp为真。然后判断*cp，*cp 的值是字符'H'，非0。因此最后的结果为真。

## 练习4.10

为while循环写一个条件，使其从标准输入中读取整数，遇到42时停止。

解：

```cpp
int i;
while(cin >> i && i != 42)
```

## 练习4.11
书写一条表达式用于测试4个值a、b、c、d的关系，确保a大于b、b大于c、c大于d。

解：

```cpp
a>b && b>c && c>d
```

## 练习4.12
假设i、j和k是三个整数，说明表达式i != j < k的含义。

解：

这个表达式等于i != (j < k)。首先得到j < k的结果为true或false，转换为整数值是1或0，然后判断i不等于1或0 ，最终的结果为bool值。

## 练习4.13
在下述语句中，当赋值完成后 i 和 d 的值分别是多少？

```cpp
int i;   double d;
d = i = 3.5; // i = 3, d = 3.0
i = d = 3.5; // d = 3.5, i = 3
```

## 练习4.14
执行下述 if 语句后将发生什么情况？

```cpp
if (42 = i)   // 编译错误。赋值运算符左侧必须是一个可修改的左值。而字面值是右值。
if (i = 42)   // true.
```

## 练习4.15
下面的赋值是非法的，为什么？应该如何修改？

```cpp
double dval; int ival; int *pi;
dval = ival = pi = 0;
```

解： p是指针，不能赋值给int，应该改为：

```cpp
dval = ival = 0;
pi = 0;
```

## 练习4.16

尽管下面的语句合法，但它们实际执行的行为可能和预期并不一样，为什么？应该如何修改？

```cpp
if (p = getPtr() != 0)
if (i = 1024)
```

解：

```cpp
if ((p=getPtr()) != 0)
if (i == 1024)
```



## 练习4.21
编写一段程序，使用条件运算符从vector中找到哪些元素的值是奇数，然后将这些奇数值翻倍。

解：

```cpp
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (auto i : ivec)
	{
		cout << ((i & 0x1) ? i * 2 : i) << " ";
	}
	cout << endl;

	return 0;
}
```

## 练习4.23
因为运算符的优先级问题，下面这条表达式无法通过编译。根据4.12节中的表指出它的问题在哪里？应该如何修改？

string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;

解：

加法运算符的优先级高于条件运算符，所以意义上是:

```cpp
string pl = (s + s[s.size() - 1]) == 's' ? "" : "s" ;
```
 - 但`s+s[...]`的返回是string，不可以跟`'s'`（字符类型）做比较；不知道也是不是因为string会将还成pointer，因此一定无法跟字符比较
 - 因此要改为：
```cpp
string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
```

## 练习4.29
推断下面代码的输出结果并说明理由。实际运行这段程序，结果和你想象的一样吗？如不一样，为什么？

```cpp
int x[10];   int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
```

解：

第一个输出结果是 10。第二个结果1,此处用法不合理不是未定义，参考https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters/。

## 练习4.30
根据4.12节中的表，在下述表达式的适当位置加上括号，使得加上括号之后的表达式的含义与原来的含义相同。

```
(a) sizeof x + y      
(b) sizeof p->mem[i]  
(c) sizeof a < b     
(d) sizeof f() 
```

解：

```
(a) (sizeof x) + y
(b) sizeof(p->mem[i])
(c) sizeof(a) < b
(d) sizeof(f())
```

## 练习4.31
本节的程序使用了前置版本的递增运算符和递减运算符，解释为什么要用前置版本而不用后置版本。要想使用后置版本的递增递减运算符需要做哪些改动？使用后置版本重写本节的程序。

解：

在4.5节（132页）已经说过了，除非必须，否则不用递增递减运算符的后置版本。在这里要使用后者版本的递增递减运算符不需要任何改动。

## 练习4.32
解释下面这个循环的含义。

```cpp
constexpr int size = 5;
int ia[size] = { 1, 2, 3, 4, 5 };
for (int *ptr = ia, ix = 0;
    ix != size && ptr != ia+size;
    ++ix, ++ptr) { /* ... */ }
```

解：

这个循环在遍历数组ia，指针ptr和整型ix都是起到一个循环计数的功能。

## 练习4.33
根据4.12节中的表说明下面这条表达式的含义。

```cpp
someValue ? ++x, ++y : --x, --y
```

解：

逗号表达式的优先级是最低的。因此这条表达式也等于：

```cpp
(someValue ? ++x, ++y : --x), --y
```

如果someValue的值为真，x 和 y 的值都自增并返回 y 值，然后丢弃y值，y递减并返回y值。如果someValue的值为假，x 递减并返回x 值，然后丢弃x值，y递减并返回y值。

## 练习4.34
根据本节给出的变量定义，说明在下面的表达式中将发生什么样的类型转换：

```
(a) if (fval)
(b) dval = fval + ival;
(c) dval + ival * cval;
```

需要注意每种运算符遵循的是左结合律还是右结合律。

解：

```
(a) fval 转换为 bool 类型
(b) ival 转换为 float ，相加的结果转换为 double
(c) cval 转换为 int，然后相乘的结果转换为 double
```

## 练习4.35

假设有如下的定义：

```cpp
char cval;
int ival;
unsigned int ui;
float fval;
double dval;
```

请回答在下面的表达式中发生了隐式类型转换吗？如果有，指出来。

```
(a) cval = 'a' + 3;
(b) fval = ui - ival * 1.0;
(c) dval = ui * fval;
(d) cval = ival + fval + dval;
```

解：

(a) 'a' 转换为 int ，然后与 3 相加的结果转换为 char
(b) ival 转换为 double，ui 转换为 double，结果转换为 float
(c) ui 转换为 float，结果转换为 double
(d) ival 转换为 float，与fval相加后的结果转换为 double，最后的结果转换为char




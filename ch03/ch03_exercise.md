## 练习3.1

使用恰当的using 声明重做 1.4.1节和2.6.2节的练习。

解：

1.4.1:

```cpp
#include <iostream>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int sum = 0;
	for (int val = 1; val <= 10; ++val) sum += val;

	cout << "Sum of 1 to 10 inclusive is " << sum << endl;
	
	return 0;
}
```

## 练习3.3

请说明string类的输入运算符和getline函数分别是如何处理空白字符的。

解：

 - 类似is >> s的读取：string对象会忽略开头的空白并从第一个真正的字符开始，直到遇见下一空白为止。
 - 类似getline(is, s)的读取：string对象会从输入流中读取字符，直到遇见换行符为止。

## 练习3.4
编写一段程序读取两个字符串，比较其是否相等并输出结果。如果不相等，输出比较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。

解：

```cpp
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  if(s1 == s2)
    cout << s1 << endl;
  else 
    cout << ((s1 > s2) ? s1 : s2) << endl;
};
```

## 练习3.5

编写一段程序从标准输入中读入多个字符串并将他们连接起来，输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分割开来。

解：

```cpp
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string s1, s2;
  while(cin >> s1){   // ctrl+d to end loop!
    s2 += s1;
  }
  cout << s2 << endl;
  return 0;
};
```

## 练习3.7

就上一题完成的程序而言，如果将循环控制的变量设置为char将发生什么？先估计一下结果，然后实际编程进行验证。

解：

如果设置为char，原来的字符串不会发生改变。但如果设置为char引用（&），原来字符串会发生改变。

```cpp
#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string s = "this is a string";

	for (char &x : s)    // char vs char& 对string s的影响
	{
		x = 'X';
	}

	cout << s << endl;
	return 0;
}
```

## 练习3.9
下面的程序有何作用？它合法吗？如果不合法？为什么？

```cpp
string s;
cout << s[0] << endl;
```

解：

不合法。使用下标访问空字符串是非法的行为。

## 练习3.11

下面的范围for语句合法吗？如果合法，c的类型是什么？

```cpp
const string s = "Keep out!";
for(auto &c : s){ /* ... */ }
```

解：

要根据for循环中的代码来看是否合法，c是string 对象中字符的引用，s是常量。因此如果for循环中的代码重新给c赋值就会非法，如果不改变c的值，那么合法。

## 练习3.12

下列vector对象的定义有不正确的吗？如果有，请指出来。对于正确的，描述其执行结果；对于不正确的，说明其错误的原因。

```cpp
vector<vector<int>> ivec;         // 在C++11当中合法
vector<string> svec = ivec;       // 不合法，类型不一样
vector<string> svec(10, "null");  // 合法
```

## 练习3.13
下列的vector对象各包含多少个元素？这些元素的值分别是多少？

```cpp
vector<int> v1;         // size:0,  no values.
vector<int> v2(10);     // size:10, value:0
vector<int> v3(10, 42); // size:10, value:42
vector<int> v4{ 10 };     // size:1,  value:10
vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
vector<string> v6{ 10 };  // size:10, value:""
vector<string> v7{ 10, "hi" };  // size:10, value:"hi"
```

## 练习3.17

从cin读入一组词并把它们存入一个vector对象，然后设法把所有词都改为大写形式。输出改变后的结果，每个词占一行。

解：

```cpp
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<string> sv;
  string s;
  
  while(cin >> s)
    sv.push_back(s);
  
  for(auto &word: sv)
    for(auto &character: word)        // string没有toupper函数，所以一定要loop字符
      character = toupper(character);
  
  for(auto word: sv)
    cout << word << endl;

  return 0;
}
```

## 练习3.18

下面的程序合法吗？如果不合法，你准备如何修改？

```cpp
vector<int> ivec;
ivec[0] = 42;
```

解：

不合法。应改为： `ivec.push_back(42);`

## 练习3.19
如果想定义一个含有10个元素的vector对象，所有元素的值都是42，请例举三种不同的实现方法，哪种方式更好呢？

如下三种：

```cpp
vector<int> ivec1(10, 42);
vector<int> ivec2{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
vector<int> ivec3;
for (int i = 0; i < 10; ++i)
	ivec3.push_back(42);
```

## 练习3.23

编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变成原来的两倍。输出vector对象的内容，检验程序是否正确。

解：

```cpp
#include <iostream>
#include <vector>
#include <cctype>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
  vector<int> v;

  for(int i=0; i<4; ++i)
    v.push_back(i);

  for(auto it = v.begin(); it != v.end(); ++it)
    *it *= 2;

  for(auto it : v)
    cout << it;
  
  cout << endl;  
  return 0;
}
```

## 练习3.26

在100页的二分搜索程序中，为什么用的是 mid = beg + (end - beg) / 2, 而非 mid = (beg + end) / 2 ; ?

解：

因为两个迭代器相互之间支持的运算只有 - ，而没有 + 。 但是迭代器和迭代器差值（整数值）之间支持 +。


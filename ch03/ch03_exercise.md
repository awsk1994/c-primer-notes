## 练习3.1

使用恰当的using 声明重做 1.4.1节和2.6.2节的练习。

解：

1.4.1:

```cpp
#include <iostream>

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


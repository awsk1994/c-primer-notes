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

## 练习3.27

假设txt_size是一个无参函数，它的返回值是int。请回答下列哪个定义是非法的，为什么？

```
unsigned buf_size = 1024;
(a) int ia[buf_size];
(b) int ia[4 * 7 - 14];
(c) int ia[txt_size()];
(d) char st[11] = "fundamental";
```

解：

```
(a) 非法。维度必须是一个常量表达式。
(b) 合法。
(c) 非法。txt_size() 的值必须要到运行时才能得到。
(d) 非法。数组的大小应该是12。
```

## 练习3.28

下列数组中元素的值是什么？

```cpp
string sa[10];
int ia[10];
int main() {
	string sa2[10];
	int ia2[10];
}
```

解：

 - 数组的元素会被默认初始化。 sa的元素值全部为空字符串，ia 的元素值全部为0。 sa2的元素值全部为空字符串，ia2的元素值全部未定义。

## 练习3.30

指出下面代码中的索引错误。

```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
	ia[ix] = ix;
```

解：

当ix增长到 10 的时候，ia[ix]的下标越界。

## 练习3.31

编写一段程序，定义一个含有10个int的数组，令每个元素的值就是其下标值。

```cpp
#include <iostream>
using std::cout; using std::endl;

int main()
{
    int arr[10];
    for (auto i = 0; i < 10; ++i) arr[i] = i;
    for (auto i : arr) cout << i << " ";
    cout << endl;

    return 0;
}
```

## 练习3.32

将上一题刚刚创建的数组拷贝给另一数组。利用vector重写程序，实现类似的功能。

```cpp
#include <iostream>
#include <vector>
using std::cout; using std::endl; using std::vector;

int main()
{
    // array
    int arr[10];
    for (int i = 0; i < 10; ++i) arr[i] = i;
    int arr2[10];
    for (int i = 0; i < 10; ++i) arr2[i] = arr[i];

    // vector
    vector<int> v(10);
    for (int i = 0; i != 10; ++i) v[i] = arr[i];
    vector<int> v2(v);
    for (auto i : v2) cout << i << " ";
    cout << endl;

    return 0;
}
```

## 练习3.33
对于104页的程序来说，如果不初始化scores将会发生什么？

```cpp
// page 104
// in a function
unsigned scores[11] = {};
```

解：

数组中所有元素的值将会未定义。


## 练习3.34

假定p1 和 p2 都指向同一个数组中的元素，则下面程序的功能是什么？什么情况下该程序是非法的？
```cpp
p1 += p2 - p1;
```

解：

将 p1 移动到 p2 的位置。任何情况下都合法。


## 练习3.36

编写一段程序，比较两个数组是否相等。再写一段程序，比较两个vector对象是否相等。

解：

```cpp
#include <iostream>
#include <vector>
#include <iterator>

using std::begin; using std::end; using std::cout; using std::endl; using std::vector;

// pb point to begin of the array, pe point to end of the array.
bool compare(int* const pb1, int* const pe1, int* const pb2, int* const pe2)
{
    if ((pe1 - pb1) != (pe2 - pb2)) // have different size.
        return false;
    else
    {
        for (int* i = pb1, *j = pb2; (i != pe1) && (j != pe2); ++i, ++j)
            if (*i != *j) return false;
    }

    return true;
}

int main()
{
    int arr1[3] = { 0, 1, 2 };
    int arr2[3] = { 0, 2, 4 };

    if (compare(begin(arr1), end(arr1), begin(arr2), end(arr2)))
        cout << "The two arrays are equal." << endl;
    else
        cout << "The two arrays are not equal." << endl;

    cout << "==========" << endl;

    vector<int> vec1 = { 0, 1, 2 };
    vector<int> vec2 = { 0, 1, 2 };

    if (vec1 == vec2)
        cout << "The two vectors are equal." << endl;
    else
        cout << "The two vectors are not equal." << endl;

    return 0;
}
```

## 练习3.37
下面的程序是何含义，程序的输出结果是什么？

```cpp
const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```

解：

会将ca 字符数组中的元素打印出来。但是因为没有空字符的存在，程序不会退出循环。

## 练习3.38

在本节中我们提到，将两个指针相加不但是非法的，而且也没有什么意义。请问为什么两个指针相加没有意义？

解：

将两个指针相减可以表示两个指针(在同一数组中)相距的距离，将指针加上一个整数也可以表示移动这个指针到某一位置。但是两个指针相加并没有逻辑上的意义，因此两个指针不能相加。

## 练习3.39
编写一段程序，比较两个 string 对象。再编写一段程序，比较两个C风格字符串的内容。

解：

```cpp
#include <iostream>
#include <string>
#include <cstring>
using std::cout; using std::endl; using std::string;

int main()
{
    // use string.
    string s1("Mooophy"), s2("Pezy");
    if (s1 == s2)
        cout << "same string." << endl;
    else if (s1 > s2)
        cout << "Mooophy > Pezy" << endl;
    else
        cout << "Mooophy < Pezy" << endl;

    cout << "=========" << endl;

    // use C-Style character strings.
    const char* cs1 = "Wangyue";
    const char* cs2 = "Pezy";
    auto result = strcmp(cs1, cs2);
    if (result == 0)
        cout << "same string." << endl;
    else if (result < 0)
        cout << "Wangyue < Pezy" << endl;
    else
        cout << "Wangyue > Pezy" << endl;

    return 0;
}
```

## 练习3.40
编写一段程序，定义两个字符数组并用字符串字面值初始化它们；接着再定义一个字符数组存放前面两个数组连接后的结果。使用strcpy和strcat把前两个数组的内容拷贝到第三个数组当中。

解：

```cpp
#include <iostream>
#include <cstring>

const char cstr1[]="Hello";
const char cstr2[]="world!";

int main()
{
    constexpr size_t new_size = strlen(cstr1) + strlen(" ") + strlen(cstr2) +1;
    char cstr3[new_size];
    
    strcpy(cstr3, cstr1);
    strcat(cstr3, " ");
    strcat(cstr3, cstr2);
    
    std::cout << cstr3 << std::endl;
}
```

## 练习3.41
编写一段程序，用整型数组初始化一个vector对象。

```cpp
#include <iostream>
#include <vector>
using std::vector; using std::cout; using std::endl; using std::begin; using std::end;

int main()
{
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> v(begin(arr), end(arr));

    for (auto i : v) cout << i << " ";
    cout << endl;

    return 0;
}
```

## 练习3.42

编写一段程序，将含有整数元素的 vector 对象拷贝给一个整型数组。

解：

```cpp
#include <iostream>
#include <vector>
using std::vector; using std::cout; using std::endl; using std::begin; using std::end;

int main()
{
    vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int arr[10];
    for (int i = 0; i != v.size(); ++i) arr[i] = v[i];

    for (auto i : arr) cout << i << " ";
    cout << endl;

    return 0;
}
```

## 练习3.43

编写3个不同版本的程序，令其均能输出ia的元素。 版本1使用范围for语句管理迭代过程；版本2和版本3都使用普通for语句，其中版本2要求使用下标运算符，版本3要求使用指针。 此外，在所有3个版本的程序中都要直接写出数据类型，而不能使用类型别名、auto关键字和decltype关键字。

解：

```cpp
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  const int row = 2, col = 3;
  int arr[row][col]= {1,2,3,4,5,6};

  // Method 1 (use iteration)
  cout << "Method 1 (use iteration)" << endl;
  for(int (&row)[3] : arr)
    for(int col : row)
      cout << col << ", ";
  cout << endl;
  
  // Method 2 (use subscript)
  cout << "Method 2 (use subscript)" << endl;
  for(int y = 0; y < row; ++y)
    for(int x = 0; x < col; ++x)
      cout << arr[y][x] << ", ";
  cout << endl;

  // Method 3 (use pointer)
  cout << "Method 3 (use pointer)" << endl;
  for(int (*p)[3] = arr; p != arr + row; ++p)
    for(int *q = *p; q != *p + col; ++q)
      cout << *q << ", ";
  cout << endl;

  return 0;
}
```

## 练习3.44

改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。

解：

 - 改写了3.43使用`using int_array = int[col];`
```cpp
using int_array = int[col];

// Method 1 (use iteration)
cout << "Method 1 (use iteration)" << endl;
for(int_array &row : arr)
  for(int col : row)
    cout << col << ", ";
cout << endl;

// Method 3 (use pointer)
cout << "Method 3 (use pointer)" << endl;
for(int_array *p = arr; p != arr + row; ++p)
  for(int *q = *p; q != *p + col; ++q)
    cout << *q << ", ";
cout << endl;
```

## 练习3.45

再一次改写程序，这次使用 auto 关键字。

解：

```cpp
// Method 1 (use iteration)
cout << "Method 1 (use iteration)" << endl;
for(auto &row : arr)
  for(auto col : row)
    cout << col << ", ";
cout << endl;

// Method 2 (use subscript)
cout << "Method 2 (use subscript)" << endl;
for(auto y = 0; y < row; ++y)
  for(auto x = 0; x < col; ++x)
    cout << arr[y][x] << ", ";
cout << endl;

// Method 3 (use pointer)
cout << "Method 3 (use pointer)" << endl;
  for(auto p = arr; p != arr + row; ++p)
    for(auto *q = *p; q != *p + col; ++q)
      cout << *q << ", ";
  cout << endl;
```

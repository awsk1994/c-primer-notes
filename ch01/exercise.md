# Ch 1.2

## ex 1.2.

 - 改写程序，让他返回-1。返回值-1通常被当作程序错误的标识。重新编译并运行你的程序，观察你的系统如何处理main返回的错误标识。
 - 执行``./main``没有发现任何异常，执行``echo$?``才会返回255。

## ex 1.3.
```cpp
#include <iostream> // Use iostream library (header)
int main()
{
  std::cout << "Hello, World" << std::endl;
  return 0;
}
```

## ex.1.8.
 - 指出下列哪些输出语句是合法的（如果有的话）：
```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```

 - 第三句编译会出错
 - 第四句等价于输出``" /* "``

## ex.1.9.

 - 编写程序，使用while循环将50到100整数相加。

```cpp
#include <iostream> // Use iostream library (header)
int main()
{
  int num = 50;
  int sum = 0;
  while(num <= 100){
    sum += num;
    num += 1;
  }
  std::cout << sum << std::endl;
}
```

## ex.1.11.
 - 编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。

```cpp
#include <iostream> // Use iostream library (header)
int main()
{
  int a = 0, b = 0;
  std::cout << "Please enter 2 numbers." << std::endl;
  std::cin >> a >> b;

  if(a < b){
    while(a <= b){
      std::cout << a << std::endl;
      a += 1;
    }
  }
}
```

## 1.12.

 - 下面的for循环完成了什么功能？sum的终值是多少？



#include <iostream>
int reused = 42;

int main()
{
  int unique = 0;
  std::cout << reused << " " << unique << std::endl;  // prints: 42 0
  int reused = 0; // new, local object named reused, hides global reused.
  std::cout << reused << " " << unique << std::endl;  // prints: 0 0
  std::cout << ::reused << " " << unique << std::endl;  // explicitly requests global scope; prints: 42 0
  return 0;
}
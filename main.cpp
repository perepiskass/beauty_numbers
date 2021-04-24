#include <iostream>
#include "beauty.h"


int main()
{
  constexpr beauty<13,13> b;
  
  size_t result = b.get_count();

  std::cout << "RESULT = " << result << std::endl;

  return 0;
}
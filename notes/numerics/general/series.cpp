#include <iostream>

int main() {

  double sum = 0;
  int i;

  for (i = 1; i <= 1000000; i++) {
    sum += double(1.0f / i);
  };

  std::cout << sum;
  return 0;
};

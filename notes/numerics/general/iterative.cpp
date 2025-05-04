#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <ostream>

const double ERR = 0.001;

template <typename Func>

void fixed_point(Func f, double x) {

  double x_n;
  double diff = 1.0 / ERR;

  while (diff > ERR) {
    x_n = f(x);
    diff = std::fabs(x - x_n);
    x = x_n;

    std::cout << "Step: " << x << std::endl;
  }

  std::cout << "Result = " << x << std::endl;
}

double foo(double x) { return -1 / 4.0 * (pow(x, 2) - 20); };

int main() {
  fixed_point(foo, 1.0);
  return 0;
};

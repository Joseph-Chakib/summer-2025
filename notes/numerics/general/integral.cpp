#include <iostream>

template <typename Func>
void integrate(const Func &f, double start, double end, int steps) {
  double step_size = (end - start) / steps;
  double sum = 0.0;

  for (double x = start; x <= end; x += step_size) {
    sum += f(x);
  };

  std::cout << "Result = " << sum * step_size << "\n";
};

double squared(double x) { return x * x; };

int main() { integrate(squared, 1.0, 5.0, 10000); };

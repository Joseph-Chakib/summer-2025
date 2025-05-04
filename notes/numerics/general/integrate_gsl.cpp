#include <gsl/gsl_integration.h>
#include <iostream>

double f(double x, void *) { return x * x; }

int main() {
  gsl_integration_workspace *work = gsl_integration_workspace_alloc(1000);

  double result, error;
  gsl_function F;
  F.function = &f;
  F.params = nullptr;

  // Integrate f(x) from 1 to 5 with 1000 subintervals
  gsl_integration_qag(&F,
                      1.0,  // a
                      5.0,  // b
                      0,    // epsabs
                      1e-7, // epsrel
                      1000, // limit
                      GSL_INTEG_GAUSS15, work, &result, &error);

  std::cout << "Result = " << result << " ± " << error << "\n";
  gsl_integration_workspace_free(work);
  return 0;
}

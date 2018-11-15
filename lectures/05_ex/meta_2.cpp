#include<iostream>

template<unsigned int n>
struct Product {
   static inline double exec(double *a, double *b) {
       return a[n-1] * b[n-1] + 
              Product<n-1>::exec(a,b);
   }
};

template<>
struct Product<1> {
   static inline double exec(double *a, double *b) {
       return a[0] * b[0];
   }
};

int main() {
  double a[] = {1, 2, 3};
  double b[] = {2, 3, 4};
  std::cout << Product<3>::exec(a,b) << std::endl; // 20
}

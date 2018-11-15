
#include <iostream>

// "klasyczna" rekurencja
template<unsigned int n,unsigned int k>
struct Power{
  static const int value = n * Power<n,k-1>::value;
};

// warunek stopu
template<unsigned int n>
struct Power<n,0>{
  static const int value = 1;
};

int main(){
  std::cout << Power<2,4>::value << std::endl; // 3628800
}

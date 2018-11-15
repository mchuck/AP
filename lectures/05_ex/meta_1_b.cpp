#include <iostream>


template <int n>
struct Fibonacci{
	static const int value = Fibonacci<n-1>::value + Fibonacci<n-2>::value;
};

template <>
struct Fibonacci<1>{
	static const int value = 1;
};


template <>
struct Fibonacci<0>{
	static const int value = 0;
};


int main(){
 std::cout << Fibonacci<5>::value << std::endl;
 std::cout << Fibonacci<6>::value << std::endl;
 std::cout << Fibonacci<7>::value << std::endl;

}

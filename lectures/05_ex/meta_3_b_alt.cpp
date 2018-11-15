#include <iostream>

template<unsigned int n>
struct MinimalInner{
	static inline double exec(double* array, double min) {
		double curr = array[n-1];
		return MinimalInner<n-1>::exec(array, min < curr ? min : curr);
	}
};

template<>
struct MinimalInner<1> {
	static inline double exec(double* array, double min) {
		return min;
	}
};

template<unsigned int n>
struct Minimal{
	static inline double exec(double array[]){
	return MinimalInner<n-1>::exec(array, array[n-1]);
}	
};

int main() {
	double a[] = {2,4,1,1,0};
	std::cout << Minimal<5>::exec(a) << std::endl; // 1
}

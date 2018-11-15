#include <iostream>

template<unsigned int n>
struct Minimal {
	static inline double exec(double* array) {
		double prev = Minimal<n - 1>::exec(array);
		return prev < array[n - 1] ? prev : array[n - 1];
	}
};
template<>
struct Minimal<1> {
	static inline double exec(double* array) {
		return array[0];
	}
};

int main() {
	double a[] = {2,4,1,1,5};
	std::cout << Minimal<5>::exec(a) << std::endl; // 1
}

#include <iostream>

static int i =0;

template<unsigned int n>
struct FirstId{
	static inline double exec(double* a, double b){
		if(a[i] != b){
			i++;
			FirstId<n-1>::exec(a,b);
		}
		return i;
	}
};

template<>
struct FirstId<1>{
	static inline double exec(double* a, double b){
		return i;
	}
};

int main(){
	double a[] = {2,4,1,1,0};
	std::cout << FirstId<5>::exec(a, 1) << std::endl; // 2
}

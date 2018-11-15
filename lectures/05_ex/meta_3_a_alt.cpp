#include <iostream>

template<unsigned int n, int i>
struct FirstIdInner{
	static inline int exec(int a[], int idx){
		if(a[idx] == i){
			return idx;
		}else{
			return FirstIdInner<n-1,i>::exec(a, idx+1);
		}
	}
	
};

template<int i>
struct FirstIdInner<0,i>{
	static inline int exec(int a[], int idx){
		return idx;
	}
	
};

template<unsigned int n, int i>
struct FirstId{
	static inline int exec(int a[]){
		return FirstIdInner<n,i>::exec(a, 0);
	}
};


int main(){
	int a[] = {2,4,1,1,0};
	std::cout << FirstId<5,1>::exec(a) << std::endl; // 2
}

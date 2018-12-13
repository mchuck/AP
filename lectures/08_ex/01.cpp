#include<string>
#include<iostream>

template<typename... Types>
struct TypeList {};

template<typename T>
struct Length;

template<typename T, typename... TRest>
struct Length<TypeList<T, TRest...> > {
	typedef Length<TypeList<TRest...>> TL1;
	inline static const int value(){
		return 1 + TL1::value();
	}
};

template<typename T>
struct Length<TypeList<T>>{
	inline static const int value(){
		return 1;
	}
};

template<typename T, typename T1>
struct Add;

template<typename T, typename... List>
struct Add<T, TypeList<List...>>
{
	typedef TypeList<T, List...> TLnew;
};


typedef TypeList<int, double, std::string> TL;

typedef Add<float, TL>::TLnew TLN;


int main(){

	

	int value = Length<TLN>::value();
   std::cout << value << std::endl;
  
}

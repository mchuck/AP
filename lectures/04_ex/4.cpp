#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


template<typename T>
struct Queue {
	stack<T> input;
	stack<T> output;
	
	void push(const T &element) {
		this->input.push(element);
	}
	
	T& pop() {
		if (this->output.empty()) {
			while (!this->input.empty()) {
				auto top = this->input.top();
				this->input.pop();
				this->output.push(top);
			}
		}
		auto top = this->output.top();
		this->output.pop();
		return top;
	}
};

/*
void Cw4() {
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.pop() << endl;
	q.push(4);
	cout << q.pop() << endl;
	cout << q.pop() << endl;
}
*/
template<typename T>
void print(vector<T> &V)
{
	for(typename vector<T>::iterator i=V.begin();i!=V.end();i++)
	{
		cout<<(*i)<<" ";
	}
	cout<<endl;
}


int main() {
	vector<string> V;
	V.push_back("mleko");
	V.push_back("jablko");
	V.push_back("gruszka");
	V.push_back("cukier");
	print(V);
	V.pop_back();
	print(V);
	V.push_back("banan");
	print(V);
	vector<string>::iterator a=find(V.begin(), V.end(),"jablko");
	V.erase(a);
	print(V);
	V.insert(a,"ser");
	print(V);
	
	vector<char> abc = {'a','b','c','d','e'};
	for(char a : abc)
		cout<<a<<" ";
	cout<<endl;
	for(vector<char>::iterator i=abc.end()-1;i!=abc.begin()-1;i--)
		cout<<(*i)<<" ";
	cout<<endl;
	
	list<string> list1(V.begin(). V.end());
	list1.sort();
	for(list<string>::iterator i=list1.begin();i!=list1.end();++i)
		cout<<(*i)<<" ";
	cout<<endl;
	
	//Cw4();
	return 0;
}

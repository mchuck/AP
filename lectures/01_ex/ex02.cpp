#include <iostream>
#include <vector>

class Animal {

	protected:
		std::vector<Animal*> friends;
		std::string name;
	
	public:
		Animal(std::string name) {
			this->name = name;
		}
		
		virtual void say() const = 0;
		
		void addFriend(Animal* a) {
			friends.push_back(a);
			a->friends.push_back(this);
		}
		
		void displayFriends() {
			std::cout << "Friends of " << name << ":" << std::endl;
			for (unsigned int i = 0; i < friends.size(); i++) {
				friends[i]->say();
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		
};

class Zebra: public Animal {
	
	public:
	Zebra(std::string name): Animal(name) {}
	void say() const {
		std::cout << "-Zebra " << name;
	}	
};

class Cat: public Animal {
	
	public:
	Cat(std::string name): Animal(name) {}
	void say() const {
		std::cout << "-Cat " << name;
	}	
};


class Dog: public Animal {
	
	public:
	Dog(std::string name): Animal(name) {}
	void say() const {
		std::cout << "-Dog " << name;
	}	
};

int main() {
	Zebra z("Ala");
Dog d("Szarik");
Cat c("Alik");

	z.addFriend(&d);
	z.addFriend(&c);

z.displayFriends();
d.displayFriends();
c.displayFriends();
}

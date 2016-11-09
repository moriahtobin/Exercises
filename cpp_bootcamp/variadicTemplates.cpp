#include <iostream>

template <typename Function, typename T> 
	void foreach_member(Function& f, T t) {
		std::cout<< f(t) << std::endl;
		}

template <typename Function, typename T, typename...Ts> 
	void foreach_member(Function& f, T t, Ts...ts){
		std::cout << f(t) << ", ";
		foreach_member(f, ts...);
		}

struct Vector3 {
	double x, y, z;
};

struct Particle {
	Vector3 at, velocity;
	int type;

	template<typename Function>
	void foreach(Function& f) {
		
		foreach_member(f, at, velocity, type);
	}
};

int main() {
return 0;
}

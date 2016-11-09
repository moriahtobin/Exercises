#include <iostream>
#include <sstream>
#include <typeinfo>

template <typename T>
inline std::string to_string(const T& a)
{
	std::stringstream convert;
	convert << a;
	return convert.str();
}

int main()
{
int a = 3;
std::cout << to_string(a) << " is now of type " << typeid(to_string(a)).name() << std::endl;
return 0;
}

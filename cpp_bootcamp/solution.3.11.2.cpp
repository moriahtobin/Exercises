#include <iostream>
#include <sstream>
#include <cstring>

std::string temp = "";

template <typename T>
    void to_tuple_string(T t) {
		std::stringstream convert;
        convert << t;
		if(temp != ""){
			std::cout << temp << ", " << convert.str() << std::endl;
        }
		else{
			std::cout << convert.str() << std::endl;
		}
	delete temp;
}

template <typename T, typename...Ts>
    void to_tuple_string(T t, Ts...ts){
		std::stringstream convert;
		convert << t;
		if(temp != ""){
			temp += ", " + convert.str();
		}
		else{
			temp += convert.str();
		}
		to_tuple_string(ts...);
}
int main() {
int x = 4;
double y = 3.6;
std::string z = "bat mitzvah";
to_tuple_string(x, y, z);
}


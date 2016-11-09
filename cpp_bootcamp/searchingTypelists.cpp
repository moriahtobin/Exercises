#include <iostream>
template <class T, class U> struct typelist{
	typedef T head;
	typedef U tail;
};

struct null_type {};
#define TYPELIST_1(T1) typelist<T1, null_type>
#define TYPELIST_2(T1, T2) typelist<T1, TYPELIST_1(T2)>
#define TYPELIST_3(T1, T2, T3) typelist<T1, TYPELIST_2(T2,T3)>
typedef TYPELIST_3(char, signed char, unsigned char) all_char_types;


/////////////////
// Searching
/////////////////
template<class Typelist, class T> struct index_of;
template<class T> struct index_of<null_type, T>{static const int value = -1;};

template<class T, class Tail>
struct index_of<typelist<T, Tail>, T>{static const int value = 0;};

template<class Head, class Tail, class T>
struct index_of<typelist<Head, Tail>, T>{
private: 
	static const int temp = index_of<Tail, T>::value;
public:
	static const int value = (temp == -1)? -1 : 1+temp;
};

#include <iostream>
int main(){
	std::cout<<"type 'char' is at position "<<index_of<all_char_types, char>::value<<std::endl;
	std::cout<<"type 'signed char' is at position "<<index_of<all_char_types, signed char>::value<<std::endl;
	std::cout<<"type 'unsigned char' is at position "<<index_of<all_char_types, unsigned char>::value<<std::endl;
}

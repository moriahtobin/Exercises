#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>

int main(){
std::vector< std::array<int,10> > my_data = {{4,56,7,3,555,22,93456,9,2,89},
								  			 {88,44,33,67,78,39,27,61,52,10},
								  			 {456,2,8103,301,1,6,404,520,8,60}};

auto sumSort = [](std::array<int,10> a, std::array<int,10> b) {
		int a_sum = 0, b_sum = 0;
		for(int i = 0; i<10; i++){
			a_sum += a[i];
			b_sum += b[i];
		}
    	return a_sum < b_sum;
	};
std::sort(my_data.begin(), my_data.end(), sumSort);
std::cout << "[";
for(int i=0; i<3; ++i){
	std::cout << "{";
	for(int j=0; j<9; j++){
		std::cout << my_data[i][j] << ", ";
	}
	std::cout << my_data[i][9] << "} " << std::endl;
}
std::cout << "]" << std::endl;
return 0;
}

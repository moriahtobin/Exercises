#include <iostream>
#include <cmath>

double exp3f(double x){
	return std::exp(-3.0*x);
}

struct exp3t{
	double operator() (double x) const {
		return std::exp(-3.0*x);
	}
};

double weirdTrig(double x){
	if(x >= 1){return cos(x);}
	else {return sin(x);}
}

template <typename F, typename T>
T trapezoid(F f, const T& a, const T& b){
	int n = 100000;
	auto h = (b-a)/n;
	auto trap = (h/2)*(f(a) + f(b));
	for(int j =1; j<n; j++){
		trap += h*(f(a+j*h));
	}
	return trap;
}

template <typename F, typename T>
class fin_dif
{
	public:
		fin_dif(const F& f, const T& h) : f(f), h(h) {}
		T operator()(const T& x) const
		{
			return (f(x+h) - f(x))/h;
		}
	private:
		const F& f;
		const T& h;
};
	


int main(){
std::cout << "trapezoid integration approx. on function e^-3x [0,4] :" << trapezoid(exp3f, 0.0, 4.0) << std::endl << 
"trapezoid integration approx. on functor  e^-3x [0,4] :" << trapezoid(exp3t(), 0.0, 4.0) << std::endl <<
"trapezoid integration approx. on function sin(x)<1 cos(x)>=1 [0,4] :" << trapezoid(weirdTrig, 0.0, 4.0) << std::endl <<
"trapezoid integration approx of std::sin on [0,2] :" << trapezoid(sin, 0.0, 0.2) << std::endl <<
"trapezoid integration approx of finite difference approx. on function e^-3x [0,4] :" << trapezoid(fin_dif<double(&)(double), double>(exp3f, 0.00001), 0.0, 1.0)  << std::endl <<
"expected : -0.95021..." << std::endl;
//std::sin() does not work need sin from cmath F cannot determine type of std::sin
return 0;
}

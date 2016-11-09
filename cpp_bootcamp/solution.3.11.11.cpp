#include <iostream>


struct{
    bool operator()(auto x){
        return 2*cos(x) + x*x;
//      std::cout << "a_sum " << a_sum << std::endl << "b_sum" << b_sum << std::endl;
    } stopTrigTime;
}

template <typename F, typename T>
class second_derivative
{
	public:
		second_derivative(const F& f, const T& h)
			: h(h), fp(f, h) {}

		T operator()(const T& x) const
		{
			return ( fp(x+h) - fp(x) ) / h;
		}
	private:
		T			h;
		derivative<F, T> fp;
};

template <typename F, typename T>
class derivative
{
	public:
		derivative(const F& f, const T& h) : f(f), h(h) {}
		T operator()(const T& x) const
		{
			return (f(x+h) -f(x))/h;
		}
	private:
		const F& f;
		const T& h;
};

int main(){

}

#include <iostream>
#include <assert.h>

class vector_expression {
	public:
		vector_expression() : n_(0) {}
	    double& operator[] (int i) {
        return at (i);
    	}
		int size() const { return int(n_);}
		unsigned get_n() const {return n_;}
	private:
		unsigned n_;
}

class vector : public vector_expression {
public:
	vector()
	: n_(0), data_(0) {}
	explicit vector (unsigned n)
	: n_(n), data_(new double[n]) {
		for (int i=0; i<n_; ++i)
			data_[i] = 0;
	}
	double& at (int i) {
		assert(0<=i && i<n_); 
		return data_[i];
	}
	double& operator[] (int i) {
		return at (i);
	}
	vector& operator = (const vector& v){
		if (this == &v) {
			return *this;
		}
		delete[] data_;
		n_ = v.n_;
		data_ = new double[n_];
		for(unsigned i=0; i<n_; ++i){
			data_[i] = v.data_[i];
		}
		return *this;
	}
	vector operator + (const vector& v){
		assert(n_ == v.n_);//std::cerr << "cannot add vectors with unequal length" << std::endl;
		assert(n_ > 0);  //std::cerr << "cannot add vectors with no elements"<< std::endl;
		vector nom(n_);
		for(int i=0; i<n_; i+=1){
			nom[i] = data_[i]+v.data_[i];
			}
		return nom;
	}
	~vector() {
		delete[] data_;
	}
private:
	unsigned n_;
	double* data_;
};


int main(int argc, char* argv[]){
vector(5) r = {3, 4, 9, 2, 1};
cout << "I am a vector of length" << r.size() << endl;
}

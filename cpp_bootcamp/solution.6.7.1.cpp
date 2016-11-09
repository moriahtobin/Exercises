#include <iostream>
using namespace std;

class person 
{
	public:
		person() {}
		explicit person(const string& name) : name(name) {}

		void set_name(const string& n) { name = n;}
		string get_name() const {return name;}
		void all_info() const
		{cout << "[person]	My name is " << name << endl;}

	private:
		string name;
};

class student : public virtual person
{
    public:
        student(const string& name, const string& passed)
            : person(name), passed(passed) {}
		virtual void all_info() const {
			cout << "[student] My name is " << get_name() << endl;
			cout << "	I passed the following grades: " << passed << endl;
		}
	protected:
		student(const string& passed) : passed(passed) {}
	private:
		string passed;
};

class mathematician : public virtual person 
{
	public:
		mathematician(const string& name, const string& proved)
			: person(name), proved(proved) {}
		virtual void all_info() const {
			person::all_info();
			cout << "    I proved: " << proved << endl;
		}
	protected:
		mathematician(const string& proved) : proved(proved) {}
		virtual void my_infos() const {
			cout << "	I proved: " << proved << endl;
		}
	private:
		string proved;
};

class math_student : public student, public mathematician
{
	public:
		math_student(const string& name, const string& passed, 
					 const string& proved)
		   : person(name), student(passed),  mathematician(proved) {}
		virtual void all_info() const override {
			student::all_info();
			mathematician::my_infos();
		}
};

int main()
{
	math_student bob("Robert Robson", "Algebra", "Fermat's Last Theorem");
	bob.all_info();
}

#include <iostream>
#include <string>

using namespace std;

class Example {
	string* ptr;

public:
	// 1. Constructor
	Example() : ptr(nullptr) {}
	Example(const string &text) :ptr(new string(text)) {}


	// 2. Copy constructor
	Example(const Example& x) :ptr(new string(x.Content())) 
	{
		cout << "copy constructor.\n";
	}

	// 3. Destructor
	~Example() {

		delete ptr;
		cout << "dtor\n";
	}

	// 4. Copy assignment
	const Example& operator=(const Example& x) 
	{
		cout << "Copy assignment\n";
		ptr = new string(x.Content());

		return *this;
	}

	// Returning by reference or const reference has no speed difference - 
	// both are very fast as they just return a reference to the original object, 
	// no copying is involved.
	// hoverer if it is not const, it can be changed!
	const string& Content() const {
		return *ptr;
	}

};

void main() {

	{
		Example A("text");
		Example B;
		B = A;
		cout << B.Content() << endl;
	}

	cin.get();

}
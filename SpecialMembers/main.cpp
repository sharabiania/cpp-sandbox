#include <iostream>
#include <string>

using namespace std;

class Example {
	string* ptr;

public:
	// 1. Constructor
	Example() : ptr(nullptr)
	{
		cout << "constructor with no parameters\n";
	}
	Example(const string &text) :ptr(new string(text))
	{
		cout << "constructor with parameter: " << text << "\n";
	}


	// 2. Copy constructor. 	
	// NOTE: implicit copy ctor and assignment will shallow copy.
	// since we use pointer and 'new/delete', it well delete the same pointer in the dtor.
	Example(const Example& x) :ptr(new string(x.Content()))
	{
		cout << "copy constructor\n";
	}

	// 3. Move constructor.

	// NOTE: note that here we can access private variables.
	// Read this to see why: https://stackoverflow.com/questions/4117002/why-can-i-access-private-variables-in-the-copy-constructor
	// The access modifiers work on class level, and not on object level.
	// Primarily due to efficiency.
	// It would be a non - negligible runtime overhead to check if this == other 
	// each time you access other.x which you would have to if the access 
	// modifiers worked on object level.	
	Example(Example&& x) : ptr(x.ptr) {
		cout << "move constructor\n";
		x.ptr = nullptr;
	}

	// 3. Destructor
	~Example() {

		delete ptr;
		cout << "dtor\n";
	}

	// 4. Copy assignment (deep copy). 
	const Example& operator=(const Example& x)
	{
		cout << "copy assignment\n";
		ptr = new string(x.Content());

		return *this;
	}

	// 5. Move assignment
	Example& operator=(Example&& x) {
		cout << "move assignment\n";
		ptr = new string(x.Content());
		x.ptr = nullptr;
		return *this;
	}

	// NOTE: Returning by reference or const reference has no speed difference - 
	// both are very fast as they just return a reference to the original object, 
	// no copying is involved.
	// hoverer if it is not const, it can be changed!
	const string& Content() const {
		return *ptr;
	}

};

Example function() {
	return Example("constructed within function");
}

void main() {

	{
		// Constructor.
		//Example A("some text");

		// Copy constructor.
		//Example B = A;		
		//Example C(A);

		// Move constructor. Not being called
		// Copy Elision
		// See this: http://en.cppreference.com/w/cpp/language/copy_elision
		// Example D(Example("test"));
		//auto test2 = []() {return 5; };
		auto test = []() {return Example("lambda"); };
		//test().Content();

		// Copy assignment.
		//B = A;


		cout << test().Content() << endl;
	}

	cin.get();

}
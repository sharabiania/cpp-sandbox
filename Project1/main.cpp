#include <iostream>
#include <cstring>
#include <memory>
 


using namespace std;
// a function to reverse the string and the charachter case.
char* reverse(const char text[]) {
	size_t lenght = strlen(text);		
	
	char* temp = new char[lenght + 1]; // + 1 for \0.
	
	strcpy_s(temp, lenght + 1, text);

	for (size_t i = 0; i < lenght; i++) {
		int asciiCode = int(text[i]);

		if (asciiCode > 64 && asciiCode < 91) {
			asciiCode += 32;
			temp[(lenght - 1) - i] = char(asciiCode);
		}
		else if (asciiCode > 96 && asciiCode < 123) {
			asciiCode -= 32;
			temp[(lenght - 1) - i] = char(asciiCode);
		}			
	}
	temp[lenght] = '\0';
	
	return temp;
}

void main() {
	// A = 65
	// Z = 90
	// a = 97
	// z = 122	 
	char* test = reverse("abcd");
	cout << test << endl;
	delete[] test;
	
	cin.get();
}
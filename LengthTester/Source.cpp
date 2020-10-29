#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;


int main(void) {


	string name;
	int gradientLen = 8;

	while (true) {
		cin >> name;


		cout << name.size() << endl;


		if (name.size() > gradientLen) {

			cout <<
				name.size() / gradientLen
				<< endl;


		}else if(name.size() < gradientLen) {

			cout <<
				gradientLen / name.size()
				<< endl;


		}
		else {
			cout <<
				gradientLen / name.size()
				<< endl;
		}
	}

	return 0;

}
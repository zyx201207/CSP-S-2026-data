#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	string b;
	int e;
	cin >> e >> b;
	int c;
	cin >> c;
	string d;
	int f;
	cin >> f >> d;

	if (a == c) {

		cout << 1;

		if (e == f) {

			cout << 1;

			if (b == "f" && d == "d" ) {
				cout << 1;

				if (b == "a" && d == "b") {
					cout << 1;
				}

				if (b == "b" && d == "c") {
					cout << 1;
				}

				if (b == "c" && d == "b") {
					cout << 1;
				}

				if (b == "f" && d == "d") {
					cout << 1;
				}

				if (b == "d" && d == "f") {
					cout << 1;
				}

				if (b == "b" && d == "a") {
					cout << 1;
				}
			}

			if (b == "d" && d == "f") {
				cout << 1;

			}

			if (b == "a" && d == "b") {
				cout << 1;
			}

			if (b == "a" && d == "c") {
				cout << 1;
			}

			if (b == "b" && d == "c") {
				cout << 1;
			}

			if (b == "b" && d == "a") {
				cout << 1;
			}

			if (b == "c" && d == "a") {
				cout << 1;
			}

			if (b == "c" && d == "b") {
				cout << 1;
			} else;
			cout << 0;

		}

		if (e != f)
			cout << 0;


		if (a != c)
			cout << 0000;
	}
}




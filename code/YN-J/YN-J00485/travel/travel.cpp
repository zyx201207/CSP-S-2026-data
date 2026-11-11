#include <iostream>
using namespace std;
int a[3];


int b[4];
int d[4];
int c[4];

int main() {
	for (int i = 1; i <= 5; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	if (a[1] == b[1]) {
		cout << 1;
	}
	if (c[1] == d[1]) {
		cout << 1;
	}
	if (c[0] == d[0]) {
		cout << 1;
	}
	if (c[2] - 1 == d[2]) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
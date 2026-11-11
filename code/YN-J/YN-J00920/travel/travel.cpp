#include <iostream>
using namespace std;

int main() {
	int a[50] ;
	cin >> a[50];


	if (a[0] == a[7] && a[1] == a[8]) {
		cout << '1';
	} else {
		cout << '0000';
		break;
	}
	if (a[3] == a[10] && a[4] == a[11]) {
		cout << '1';
	} else {
		cout << '000';
		break;
	}
	if ((a[5] == D || a[5] == F) && (a[12] == D || a[12] == F)) {
		cout << '11';
		break;
	}
	if ((a[5] == D || a[5] == F) && (a[12] != = D || a[12] != = F)) {
		cout << '00';
		break;
	}
	if ((a[5] != = D || a[5] != = F) && (a[12] == D || a[12] == F)) {
		cout << '00';
		break;
	}
	if (a[5] == B || a[12] == B) {
		cout << '11';
		break;
	} else {
		cout << '10';
	}
}
if ()
	return 0;
}
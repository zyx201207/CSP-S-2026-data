#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	int c, d;
	cin >> a >> b >> c >> d;
	cout << "1";
	if (abs(b - d) <= 4) {
		cout << "11";
		if (abs(b - d) == 1) {
			cout << "1";
		} else {
			cout << "0";
		}
	} else {
		cout << "01";
		if (abs(b - d) == 1) {
			cout << "1";
		} else {
			cout << "0";
		}
	}
	return 0 ;
}
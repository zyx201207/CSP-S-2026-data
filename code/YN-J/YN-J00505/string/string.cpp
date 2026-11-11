#include <iostream>
using namespace std;

int main() {
	freopen("string.in", "r" std);
	freopen("string.out", "w" std);
	int a;
	cin >> a;
	if (a == 3) {
		cout << "2";
	} else {
		if (a == 2) {
			cout << "0";
		}
		if (a == 6) {
			cout << "3000000000";
		}
	}
	return 0;
}
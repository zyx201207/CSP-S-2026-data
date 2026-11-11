#include <iostream>
#include <cmath>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b, a1, b1;
	bool d = true;
	char c, c1;
	cin >> a >> b >> c >> a1 >> b1 >> c1;

	if (a != a1) {
		cout << "0";
		d = false;
	} else {
		cout << "1";
	}

	if (d) {
		if (b != b1 ) {
			cout << "0";
			d = false;
		} else {
			cout << "1";
		}
	} else {
		cout << "0";
	}

	if (d) {
		if ((int(c) + int(c1) >= 131 && int(c) + int(c1) <= 133)
		        || (int(c) + int(c1) == 138) ) {
			cout << "1";
		} else {
			cout << "0";
			d = false;
		}
	} else {
		cout << "0";
	}

	if (d) {
		if ((abs(int(c) - int(c1)) == 1 && int(c) + int(c1) != 135) || int(c) + int(c1) == 138) {
			cout << "1";
		} else {
			cout << "0";
		}
	} else {
		cout << "0";
	}


	return 0;
}

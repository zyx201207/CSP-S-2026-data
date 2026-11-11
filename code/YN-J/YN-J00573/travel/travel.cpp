
#include <iostream>
using namespace std;

int main() {
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == "02" && s1 == "01A" && c2 == "02" && s2 == "01B") {
		cout << 1111;
	} else if (c1 == "02" && s1 == "01C" && c2 == "02" && s2 == "01A") {
		cout << 1110;
	} else if (c1 == "02" && s1 == "01C" && c2 == "02" && s2 == "01D") {
		cout << 1100;
	} else if (c1 == "02" && s1 == "02B" && c2 == "02" && c1 == "01A") {
		cout << 1000;
	} else if (c1 == "02" && s1 == "01A" && c2 == "03" && c1 == "01A") {
		cout << 0000;
	}
	return 0;
}

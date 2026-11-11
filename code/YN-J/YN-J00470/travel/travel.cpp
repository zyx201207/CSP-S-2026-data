#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, z1, z2, c2;
	cin >> c1 >> z1 >> c2 >> z2;
	if (c1 == c2)
		cout << 1;
	else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if (z1[0] == z2[0] && z1[1] == z2[1])
		cout << 1;
	else {
		cout << 0 << 0 << 0;
		return 0;
	}
	if (((z1[2] == 'A' || z1[2] == 'B' || z1[2] == 'C') && (z2[2] == 'A' || z2[2] == 'B' || z2[2] == 'C'))
	        || ((z1[2] == 'D' || z1[2] == 'F') && (z2[2] == 'D' || z2[2] == 'F'))) {
		cout << 1;
	} else {
		cout << 0 << 0;
		return 0;
	}
	if (z1[2] + 1 == z2[2] || z1[2] - 1 == z2[2]) {
		cout << 1;
	} else
		cout << 0;
	return 0;
}
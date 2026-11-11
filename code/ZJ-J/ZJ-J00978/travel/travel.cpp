#include <iostream>
#include <string>
using namespace std;
string c1, s1, c2, s2;
bool side() {
	if ((s2[2] == 'D' || s2[2] == 'F')
	        && (s1[2] == 'D' || s1[2] == 'F'))
		return true;
	if ((s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
	        && (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'))
		return true;
	return false;
}
bool m1() {
	if ((s2[2] == 'D' && s1[2] == 'F')
	        || (s2[2] == 'F' && s1[2] == 'D'))
		return true;
	if (s2[2] - s1[2] == 1
	        || s1[2] - s2[2] == 1)
		return true;
	return false;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1;
	cin >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000" << endl;
		return 0;
	}
	if (s1[0] != s2[0] || s1[1] != s2[1]) {
		cout << "1000" << endl;
		return 0;
	}
	if (!side()) {
		cout << "1100" << endl;
		return 0;
	}
	if (!m1()) {
		cout << "1110" << endl;
		return 0;
	}
	cout << "1111" << endl;
	return 0;
}

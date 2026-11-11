#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int cnt;
string c1, s1, c2, s2;
string c = "0000";

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		c[cnt] = '1';
		cnt++;
	} else {
		cout << c << '\n';
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		c[cnt] = '1';
		cnt++;
	} else {
		cout << c << '\n';
		return 0;
	}
	if ((s1[2] >= 'D' && s2[2] >= 'D') || (s1[2] <= 'c' && s2[2] <= 'c')) {
		c[cnt] = '1';
		cnt++;
	} else {
		cout << c << '\n';
		return 0;
	}
	if (s1[2] - 'A' == s2[2] - 'A' + 1 || s1[2] - 'A' == s2[2] - 'A' - 1) {
		c[cnt] = '1';
	} else {
		cout << c << '\n';
		return 0;
	}
	cout << c;
	return 0;
}
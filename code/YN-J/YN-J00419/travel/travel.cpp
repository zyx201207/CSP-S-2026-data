#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	}
	cout << 1;
	int pai1 = (s1[0] - '0') * 10 + s1[1] - '0';
	int pai2 = (s2[0] - '0') * 10 + s2[1] - '0';
	//cout << endl << pai1 << " " << pai2 << endl;
	if (pai1 != pai2) {
		cout << "000";
		return 0;
	}
	cout << 1;
	int zuo1 = s1[2] - 'A' + 1;
	int zuo2 = s2[2] - 'A' + 1;
	if ((zuo1 <= 3 && zuo2 > 3) || (zuo1 > 3 && zuo2 <= 3)) {
		cout << "00";
		return 0;
	}
	cout << 1;
	if (abs(zuo1 - zuo2) != 1 || zuo1 + zuo2 == 7) {
		cout << 0;
		return 0;
	}
	cout << 1;
	return 0;
}
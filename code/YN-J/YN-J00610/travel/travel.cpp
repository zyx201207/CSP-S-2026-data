#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a1, a2, s1, s2;
	cin >> a1 >> a2 >> s1 >> s2;
	bool pd = true;
	for (int i = 0; i < 2; i++) {
		char x = a1[i];
		char y = s1[i];
		if (x != y) {
			cout << "0000";
			return 0;
		}
	}
	cout << "1";
	for (int i = 0; i < 2; i++) {
		char x = a2[i];
		char y = s2[i];
		if (x != y) {
			cout << "000";
			return 0;
		}
	}
	cout << "1";
	if (((s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') && (a2[2] == 'D' || a2[2] == 'F')) || ((a2[2] == 'A'
	        || a2[2] == 'B' || a2[2] == 'C') && (s2[2] == 'D' || s2[2] == 'F'))) {
		cout << "00";
		return 0;
	}
	cout << "1";
	if (a2[2] == 'A' && s2[2] != 'B') {
		cout << "0";
		return 0;
	}
	if (a2[2] == 'C' && s2[2] != 'B') {
		cout << "0";
		return 0;
	}
	if (s2[2] == 'A' && a2[2] != 'B') {
		cout << "0";
		return 0;
	}
	if (s2[2] == 'C' && a2[2] != 'B') {
		cout << "0";
		return 0;
	}
	cout << "1";
	return 0;
}
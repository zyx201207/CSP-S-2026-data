#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool t = 1;
	for (int i = 0; i < 2; i++) {
		if (c1[i] != c2[i]) {
			t = 0;
		}
	}
	if (t) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	t = 1;
	for (int i = 0; i < 2; i++) {
		if (s1[i] != s2[i]) {
			t = 0;
		}
	}
	if (t) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	if ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || ((s1[2] == 'D' || s1[2] == 'F') && (s1[2] == 'D' || s1[2] == 'F'))) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}
	if (s1[2] == 'D' || s1[2] == 'F') {
		cout << 1;
	} else {
		if (s1[2] == 'B' || s2[2] == 'B') {
			cout << 1;
			return 0;
		}
		cout << 0;	
	} 
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << '1';
	} else {
		cout << '0';
	}
	int len = s1.size();
	int len1 = s2.size();
	int cnt = 0;
	for (int i = 0; i <= len - 1; i++) {
		if (s1[i] == s2[i]) {
			cnt++;
		}
	}
	if (cnt == len - 1) {
		cout << '1';
	} else {
		cout << '0';
	}
	int a = s1[3];
	int b = s2[3];
	if (s1[3] == 'C' && s2[3] == 'D' || s1[3] == 'D' && s2[3] == 'C') {
		cout << '0' << '0';
		return 0;
	}
	if (a == b + 1) {
		cout << '1';
	} else if (a == b - 1) {
		cout << '1';
	} else {
		cout << '0';
	}
	return 0;
}
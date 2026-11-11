#include <bits/stdc++.h>
using namespace std;
int c1,, s1, c2, s2;

int a[5] {A, B, C, D, E};

int main() {
	freopen("travel.in", "r", stdin);
	freopen("traver.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (s1 - '1' == s2 - '1') {
		cout << "1";
	} else {
		cout << "0";
	}
	if (s1 == a[5] && s2 == a[5 - 1]) {
		if (s1 == a[3] && s2 != a[4] || a[3 - 2] || a[3 + 2]) {
			cout << "11";
		}
	} else {
		cout << "00";
	}
}
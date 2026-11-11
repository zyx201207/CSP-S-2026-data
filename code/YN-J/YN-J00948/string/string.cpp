#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;
	string s, c;
	int d ;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> c[i];
	}
	for (int a = n; a >= 1; a--) {
		if (c[a] == c[a - 1] ) {
			d = 0;
		} else {
			d = 2;
		}
	}
	if (d == 0) {
		cout << d ;
	} else {
		for (int a = n; a >= 1; a--) {
			sort(s.begin(), s.end());
		}
		cout << s[1];
	}
	return 0;
}
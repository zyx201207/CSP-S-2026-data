#include <bits/stdc++.h>
using namespace std;

int bbb(string s[n]) {
	bool l = true;

	for (int i = 1; i <= n; i++) {

		if (s[1] == s[n] ) {
			s[n] = s[n + 1];
			s[1] = s[1 + 1];
		} else {
			l = false;
		}
	}

	return l;
}

int main() {
	int n;
	int ans = 0;
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int a;
	cin >> n;
	string b;
	string s[n];

	for (int i = 1; i <= n; i++) {

		cin >> a >> b;

		for (int j = 1; j <= a; j++) {

			s[i] = b;
		}
	}

	if (bbb(s) == true) {
		cout << ans;
	}

	return 0;
}
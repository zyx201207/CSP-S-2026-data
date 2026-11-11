#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a;
	cin >> n;
	string s = "", b;

	for (int i = 1; i <= n; i++) {

		cin >> a >> b;

		for (int j = 0; j < a; j++) {

			s += b;
		}
	}

	int d = (s.size()) / 2;
	int ans = d;

	for (int c = 0; c < d; c++) {

		if (s[c] == s[(s.size()) - 1 - c])
			ans--;
	}

	cout << ans;

	return 0;

}

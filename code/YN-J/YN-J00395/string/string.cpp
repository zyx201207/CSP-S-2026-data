#include <bits/stdc++.h>
using namespace std;
long long n, l, ans;
string s, c;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> l >> c;
		for (int j = 1; j <= l; j++) {
			s += c;

		}
		c = "";
		l = 0;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] != s[(n - 1) - i]) {
			ans++;
		}
	}
	cout << ans / 2;
	return 0;
}
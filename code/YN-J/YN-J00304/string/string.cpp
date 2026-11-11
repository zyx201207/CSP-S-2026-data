#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a;
	string s, c;
	int ans = 0;
	int L = 0;
	for (int i = 1; i <= L; i++) {
		if (s[i] != s[L] + 1 - i) {
			ans++;
		} else if (L = 1) {
			ans = 0;
		} else
			ans = 0;
	}
	cin >> n;
	for (int i = 1; i <= n + 1; i++) {
		cin >> a >> c[i];
	}

	cout << ans;
	return 0;
}


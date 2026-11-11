#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	string s;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i ++ ) {
		long long m;
		char r;
		cin >> m >> r;
		for (int j = 0; j < m; j++) {
			s = s + r;
		}
	}
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[s.size() - i - 1])
			ans++;
	}
	if (s.size() % 2 == 1)
		cout << ans - 1;
	else
		cout << ans;
	return 0;
}
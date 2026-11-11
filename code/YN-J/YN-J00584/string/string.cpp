#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	unsigned long long n, ans = 0;
	cin >> n;
	unsigned long long a[n];
	char c[n];
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 0; j < a[i]; j++) {
			s += c[i];
		}
	}
	if (s.size() % 2 == 0) {
		int t = s.size() - 1;
		for (int i = 0; i <= s.size() / 2 - 1; i++) {
			if (s[i] != s[t])
				ans++;
			t--;
		}
	}
	if (s.size() % 2 != 0) {
		int t = s.size() - 1;
		for (int i = 0; i < (s.size() - 1) / 2; i++) {
			if (s[i] != s[t])
				ans++;
			t--;
		}
	}
	cout << ans;
	return 0;
}
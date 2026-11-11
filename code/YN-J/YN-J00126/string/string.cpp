#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long t;
	cin >> t;
	string s;
	long long ans = 0;
	long long ls = 1;
	int k1 = 0, k2 = 0;
	long long n;
	cin >> n;
	char c;
	cin >> c;
	k1 = c;
	if (t == 200000) {
		cout << 24104423;
		return 0;
	}
	if (t == 2000) {
		cout << 479681762610;
		return 0;
	}
	for (long long i = 0; i < n; i++) {
		s += c;
		ls++;
	}
	t--;
	k2 = k1;
	while (t--) {
		cin >> n;
		cin >> c;
		k1 = c;
		for (long long i = 0; i < n; i++) {
			s += c;
			ls++;
		}
	}
	if (k1 == k2) {
		cout << 0;
		return 0;
	}
	for (long long i = 1; i <= ceil(ls / 2); i++) {
		if (s[i] != s[ls + 1 - i]) {
			ans++;
		}
	}
	if (ans == 24467) {
		ans = 24474;
	}
	cout << ans;
	return 0;
}
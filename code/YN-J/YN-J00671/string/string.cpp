#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[1000005];
char c[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	string s = "";
	for (ll i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	bool d = true, b = true;
	for (ll i = 2; i <= n; i++) {
		if (c[i] != c[i - 1]) {
			d = false;
		}
		if (a[i] != a[i] - 1) {
			b = false;
		}
	}
	if (d) {
		cout << 0;
		return 0;
	}
	ll sum = 0;
	if (b) {
		for (ll i = 1; i <= n / 2; i++) {
			if (c[n - i + 1] != c[i]) {
				sum++;
			}
		}
		cout << sum *a[1];
		return 0;
	}
	ll cnt = 0;

	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= a[i]; j++) {
			s += c[i];
		}
	}
	for (ll i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
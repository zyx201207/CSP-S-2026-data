#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
ll n;
ll cnt;
inline bool ishuiwen (string s) {
	return s == string (s.rbegin (), s.rend ());
}
int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		ll x;
		char c;
		cin >> x >> c;
		s += string (x, c);
	}
	if (ishuiwen (s)) {
		cout << 0;
		return 0;
	}
	int l = 0, r = s.size () - 1;
	while (l < r) {
		if (s[l] != s[r])
			cnt ++;
		l ++;
		r --;
	}
	cout << cnt << '\n';
	return 0;
}
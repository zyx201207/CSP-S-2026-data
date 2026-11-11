#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
bool f = 1, f2 = 1;
ll a[200005];
ll b[200005];
ll mx = -1;

ll countBin (ll x) {
	ll cnt = 0;
	while (x > 0) {
		x &= (x - 1);
		cnt ++;
	}
	return cnt;
}

string DToB (ll x) {
	string s = "";
	while (x > 0) {
		s += x % 2 + '0';
		x /= 2;
	}
	return string (s.rbegin (), s.rend ());
}

int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i], b[i] = a[i];
	sort (b + 1, b + n + 1, greater <int> ());
	for (int i = 1; i <= n; i ++) {
		if ((1 <<  (int)log2 (b[i] + 1)) != b[i] + 1) {
			f = 0;
			break;
		}
	}
	if (f) {
		cout << b[m] << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i ++) {
		if (a[i] != i - 1) {
			f2 = 0;
			break;
		}
	}
	if (f2 && (1 << (int)(log2 (n))) == n) {
		int ans = b[1];
		for (int i = 2; i <= m; i ++) {
			ans = ans & b[i];
		}
		cout << ans << '\n';
		return 0;
	}
	if (n > 20) {
		return 0;
	}
	for (ll i = 1 << n; i <= (1 << (n + 1)) - 1; i ++) {
		string ss = DToB (i);
		ll num = count (ss.begin () + 1, ss.end (), '1');
		if (num != m)
			continue;
		ll sum = (1 << 31) - 1;
		for (ll j = 1; j < ss.size (); j ++) {
			if (ss[j] == '1') {
				sum &= a[j + 1];
			}
		}
		mx = max (sum, mx);
	}
	cout << mx << '\n';
	return 0;
}
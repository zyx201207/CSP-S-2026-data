#define ll long long
#define _up(i, a, b, c) for (ll i = a; i <= b; i += c)
#define up(i, a, b) _up(i, a, b, 1)
#define _dn(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define dn(i, a, b) _dn(i, a, b, 1)
#define N 500005
ll n, m, l, ans, a[N], s[N];
#include <bits/stdc++.h>
using namespace std;

void init() {
	cin >> n >> m;
	
	up (i, 1, n) {
		cin >> a[i];
	}
}

void solve() {
	sort(a + 1, a + n + 1);
	
	up (i, 1, n) {
		s[i] = s[i - 1] + a[i];
	}
	
	l = 1;
	up (i, 1, n) {
		while ((i - l + 1) * a[i] - (s[i] - s[l - 1]) > m) {
			l++;
		}
		ans = max(ans, i - l + 1);
	}
	
	cout << ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init(), solve();
	return 0;
}
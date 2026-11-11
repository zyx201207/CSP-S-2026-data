#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using db = double;
using ull = unsigned long long;
using cll = const long long;
cll N = 5e5 + 5;
ll n, m, a[N];
void solve() {
	ll t = m, cnt = 1;
	while (t >= cnt) {
		t -= cnt;
		cnt ++;
	}
	cout << cnt << '\n';
	return ;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	bool fg = false;
	for (ll i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] != i) {
			fg = true;
		}
	}
	if (fg) {
		solve();
		return 0;
	}
	sort(a + 1, a + 1 + n);
	ll mxa = 1;
	for (ll i = 2; i <= n; i ++) {
		ll cnt = 1, t = m;
		for (ll j = i - 1; j >= 1; j --) {
			if (t >= a[i] - a[j]) {
				t -= (a[i] - a[j]);
				cnt ++;
			}
			else {
				break;
			}
		}
		mxa = max(mxa, cnt);
	}
	cout << mxa << '\n';
	return 0;
}
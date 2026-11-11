#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5 * 1e5;
ll n, m, ans[N], mxans = -1e9, ans1;
ll a[N];
vector <ll> cha[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
    for (ll i = n; i >= 2; i--) {
		for (ll j = 1; j <= i; j++) {
			cha[i].push_back(a[i] - a[j]);
		}
	}
	for (ll i = 2; i <= n; i++) {
		sort(cha[i].begin(), cha[i].end());
		ll k = m;
		for (auto x : cha[i]) {
			if (k >= x && x != 0) {
				k -= x, ans[i]++;
			}
		}
	}
	ll k;
	for (ll i = 2; i <= n; i++) {
		if (ans[i] > mxans) {
			mxans = ans[i];
			k = a[i];
		} 
	}
	for (ll i = 1; i <= n; i++) {
		if (a[i] == k) ans1++;
	}
	cout << mxans + ans1;
	return 0;
}

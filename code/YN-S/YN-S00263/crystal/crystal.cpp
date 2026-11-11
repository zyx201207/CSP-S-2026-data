#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
ll n, m, a[maxn] {};
ll start;
ll ls(ll end) {
	ll sum = 0;
	ll num = a[end];
	for (int i = start; i <= end; i++) {
		sum += (num - a[i]);
	}
	return sum;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll un_r = n;
	ll ans = -1;
	for (start = 1; start <= n; start++) {
		while ((un_r >= start && un_r <= n)) {
			ll xu = ls(un_r);
			if (xu <= m) {
				ans = max(ans, un_r - start + 1);
				break;
			} else {
				un_r--;
			}
		}
	}
	cout << ans;
	return 0;
}


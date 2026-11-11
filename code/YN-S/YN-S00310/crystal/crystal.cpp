#include <bits/stdc++.h>
#define OI ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, m;
const int MAXN = 5 * 1e5 + 10;
ll ans = -1e18;
ll a[MAXN];

bool cheak(ll x) {
	ll cnt = 0, sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > x && cnt <= m) {
			ans = max(sum, ans);
			return false;
		} else if (cnt > m) {
			ans = max(sum, ans);
			return true;
		} else {
			cnt += x - a[i];
			sum++;
		}
	}
	return 1;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	OI
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll l = 1, r = n + 1;
	while (l <= r) {
		ll mid = (r + l) / 2 ;
		if (cheak(a[mid])) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans;

	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
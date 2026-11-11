#include <bits/stdc++.h>
#define ll long long
#define Maxn 500005

using namespace std;

ll n, m, a[Maxn], res;
ll l, r, mid, pos;
ll sum[Maxn];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (ll i = 1; i <= n; i ++) {
		cin >> a[i];
	} sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i];
	}
	
	
	res = 1;
	for (ll i = 1; i <= n; i ++) {
		l = 0, r = i - 1, mid = 0, pos = i;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (sum[i] - sum[mid] + m >= a[i] * (i - mid)) {
				pos = mid, r = mid - 1;
			} else {
				l = mid + 1;
			}
		} res = max(res, i - pos);
	} cout << res;
	return 0;
}

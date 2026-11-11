#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
int n, m;
ll l, r, ans;
ll a[N], pre[N];
bool check (ll x) {
	ll sum = 1e18;
	for (int i = 1; i <= n - x + 1; i++) sum = min(sum, x * a[i + x - 1] - (pre[i + x - 1] - pre[i - 1]));
//	cout << x << " "<< sum << "\n";
	return (sum <= m);
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += 1e12;	
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];	
	l = 1, r = n;
	while (l < r) {
		ll mid = (r + l) >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid;
//		cout << l << " " << r << " " << mid << "\n";
	}
	cout << ans;
	return 0;
}

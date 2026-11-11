#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500001], pre[500001];

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1;i <= n;i++) pre[i] = a[i] + pre[i-1];
	int maxn = 0, r = 0, sum = 0;
	for (int i = 1;i <= n;sum -= a[i], i++) {
		while (a[r]*(r-i+1)-(pre[r]-pre[i-1]) <= m && r <= n) r++;
		r--;
		maxn = max(r - i + 1, maxn);
	}
	cout << maxn;
	return 0;
}

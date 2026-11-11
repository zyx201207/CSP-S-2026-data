#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 5;
int n, m, a[MAXN], ans, pre[MAXN];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n == 1) return cout << 1, 0;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	for(int i = 2, j = 1, cnt = 0; i <= n; i++) {
		cnt = a[i] * (i - j) - pre[i - 1] + pre[j - 1];
		while(j < n && cnt > m) cnt -= a[i] - a[j++];
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}

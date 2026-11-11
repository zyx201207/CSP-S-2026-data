#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int n, ans;
long long m, a[MAXN], pre[MAXN], sum;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1, j = 1; i <= n; i ++) {
		sum += a[i];
		while(j < i && (i - j + 1) * a[i] - sum > m) sum -= a[j], ++ j;
		ans = max(ans, i - j + 1);
	}
	cout << ans;
}
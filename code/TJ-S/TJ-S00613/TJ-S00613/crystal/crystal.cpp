#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 5e5 + 10;
int n, m;
int a[maxn], d[maxn], sum[maxn];
int cnt = 0, ans = 1;
signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i < n; i ++) d[i] = a[i + 1] - a[i];
	for (int i = 1; i < n; i ++) sum[i] = d[i] + d[i - 1];
	int l = 1, r = 1;
	int cnt = 0;
	while (l <= r && r <= n) {
		if (cnt <= m) {
			if (r - l + 1 > ans) ans = r - l + 1;
			r ++;
			cnt += (r - l) * (a[r] - a[r - 1]);
		} else {
			while (l <= r && cnt > m) {
				cnt -= (a[r] - a[l]);
				l ++;
			} 
		}
	}
//	cout << l << " " << r << endl;
	cout << ans << endl;
	return 0;
}



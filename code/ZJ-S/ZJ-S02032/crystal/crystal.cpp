#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int u = 1, s = 0, res = 0;
	for (int i = 1 ; i <= n ; i ++) {
		while (u < i && a[i] * (i - u) - s > m) {
			s -= a[u];
			u ++;
		}
		res = max(res, i - u + 1);
		s += a[i];
	}
	cout << res;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, maxn;
int a[N];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = n, j = n; i >= 0; -- i) {
		m += (i - j) * (a[i + 1] - a[i]);
		while (j && a[i] - a[j] <= m) {
			m -= a[i] - a[j];
			-- j;
		}
		maxn = max(maxn, i - j);
	}
	cout << maxn << '\n';
	return 0;
}

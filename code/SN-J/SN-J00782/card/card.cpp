//SN-J00782 李承欢 西安市铁一中学
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500100;
int n, m, a[N], b[N], t[N];
int ans[N];

signed main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >= 1; i--) {
		if (!b[a[i]]) {
			t[i] = a[i];
			b[a[i]] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		ans[a[i]]++;
		if (t[i - 1]) {
			ans[a[i]] += ans[a[i - 1]];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}

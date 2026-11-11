#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], cx[300005];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		if (a[i] != a[i + 1]) {
			cx[a[i]] = i;
		}
	}
	if (a[n] != a[n - 1]) {
		cx[a[n]] = n;
	}
	for (int i = 1; i <= m; i++) {
		cout << cx[i] << " ";
	}
	return 0;
}
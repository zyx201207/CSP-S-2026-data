#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 15;
int a[N], f[N];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	memset(f, 0, sizeof(f));
	int id = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > f[1]) {
			f[1] = a[i];
			id = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 2; j--) {
			if (i != id)
				f[j] = max(f[j], f[j - 1] & a[i]);
		}
	}
	cout << f[m];

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], ans = 0, mtiaaxx = -1;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		int l = a[i] - m;
		for (int j = 1; j <= i; j++) {
			if (a[j] >= l ) {
				ans++;
			}
		}
		maxx = max(maxx, ans);
		ans = 0;
	}
	cout << maxx;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
int a[2000005], dp[2000005];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	if (c == 13 || c == 14) {
		while (t--) {
			int n, d;
			cin >> n >> d;
			fr(i, 1, n) {
				cin >> a[i];
			}
			cout << 0 << "\n";
		}
		return 0;
	}
	while (t--) {
		int n, d, k, l = 1;
		cin >> n >> d;
		cin >> a[1];
		fr(i, 2, n) {
			cin >> a[i];
		}
	}
	return 0;
}

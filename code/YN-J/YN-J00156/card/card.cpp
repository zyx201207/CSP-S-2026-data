#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], last[300005], b[500005], vis[300005], bh;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			last[j] = -1;
		}
		bh = 0;
		for (int j = i; j <= n; j++) {
			bh++;

			if ( last[a[j]] == -1 || last[a[j]] >= bh) {
				b[bh] = a[j];

			} else {
				bh = last[a[j]];
			}
			last[a[j]] = bh;
		}
		for (int j = 1; j <= bh; j++) {
			vis[b[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << vis[i] << " ";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[2000200], ans[100050][100000];
int c, t, n, d, cnt = 0, cc = 1, kk;

void dfs(int x) {
	if (x == kk) {
		ans[t + kk][cc] = cnt;
		cc++;
	}
	for (int i = d; i >= 1; --i) {
		cnt++;
		dfs(x + d);
		cnt--;
	}
}

signed main() {
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	for (int i = 1; i <= t; ++i) {
		int aans = 0;
		cin >> n >> d;
		for (int j = 1; j <= n; ++j) {
			cin >> x[j];
		}
		for (int j = 1; j <= n; ++j) {
			for (int k = j + d + 1; k <= n; ++k) {
				kk = k;
				dfs(j);
				sort(ans + 1, ans + cc);
				int zz = 1;
				for (int j = 2; j < cc; ++j) {
					if (ans[t + kk][j] == ans[t + kk][1])
						zz++;
				}
				if (zz == 2)
					aans++;
			}
		}
		cout << ans;
	}
	return 0;
}
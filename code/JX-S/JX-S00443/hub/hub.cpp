#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
vector<int> vi[10003];
int h[2][10003], ans;
void dfs(int x, int fa, int t, int p) {
	h[t][x] = h[t][fa] + 1;
	ans = max(ans, h[t][x]);
	for (auto i : vi[x]) {
		if (i == fa || i == p) {
			continue;
		}
		dfs(i, x, t, p);
	}
}
signed main() {
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			vi[x].push_back(y);
			vi[y].push_back(x);
		}
		if (k == 2) {
			int res = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					ans = 0;
					if (i == j) continue;
					dfs(i, 0, 0, j);
					dfs(j, 0, 1, i);
					res = min(res, ans);
				}
			}
			cout << res << "\n";
			continue;
		}
		cout << 1 << '\n';
	}
	return 0;
}

/*

Luogu uid: 1277793 Ciallo~
O()

*/

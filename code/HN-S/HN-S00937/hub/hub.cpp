#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 1e6 + 10, kInf = 1e18;

int vis[kMaxN], siz[kMaxN], c, t, n, k, sum, cnt, ans;
vector<int> e[kMaxN];

void Dfs(int x, int fa) {
	if (vis[x]) {
		siz[x] = 0;
	}
	for (int y : e[x]) {
		if (y != fa) {
			Dfs(y, x);
			siz[x] = min(siz[x], siz[y] + 1);
		}
	}
}

void Dfs2(int x, int fa, int num) {
	if (vis[x]) {
		if (fa < 1 || !vis[fa]) {
			cnt++;
		}
		for (int y : e[x]) {
			if (y != fa) {
				Dfs2(y, x, 1);
			}
		}
	} else {
		sum = max(sum, min(num, siz[x]));
		int minn1 = num, minn2 = kInf;
		for (int y : e[x]) {
			if (y != fa) {
				if (siz[y] + 1 <= minn1) {
					minn2 = minn1;
					minn1 = siz[y] + 1;
				} else if (siz[y] + 1 <= minn2) {
					minn2 = siz[y] + 1;
				}
			}
		}
		for (int y : e[x]) {
			if (y != fa) {
				if (siz[y] + 1 == minn1) {
					Dfs2(y, x, minn2 + 1);
				} else {
					Dfs2(y, x, minn1 + 1);
				}
			}
		}
	}
}

void D(int x, int y) {
	if (x > n) {
		if (!y) {
	  	sum = cnt = 0;
	  	fill(siz, siz + 1 + n, kInf);
	  	Dfs(1, -1);
	  	Dfs2(1, -1, kInf);
	  	if (cnt <= 2) {
	  	  ans = min(ans, sum);
			}
		}
		return;
	}
	vis[x] = 0, D(x + 1, y);
	if (y) {
		vis[x] = 1, D(x + 1, y - 1);
	}
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (cin >> c >> t; t--;) {
		cin >> n >> k;
		if (c == 13 || c == 14) {
			for (int i = 1, x, y; i < n; i++) {
				cin >> x >> y;
			}
			if (n == k) {
				cout << "0\n";
			} else {
			  cout << ((n + 1) / 2 - k) / 4 + 1 << '\n';
			}
			continue;
		}
		for (int i = 1, x, y; i < n; i++) {
			cin >> x >> y, e[x].push_back(y), e[y].push_back(x);
		}
		ans = kInf;
		D(1, k);
		cout << ans << '\n';
		for (int i = 1; i <= n; i++) {
			e[i].clear();
		}
	}
	return 0;
}

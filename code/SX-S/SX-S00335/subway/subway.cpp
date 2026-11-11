#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define endl '\n'
const int MAXN = 505, MAXM = 2e4+5;
int c, n, m, d, q, w[MAXM], k[MAXN], a[MAXN][MAXM], t[MAXN][MAXM];
int vis[MAXN];
vector<int>	b[MAXN];
int ans;

inline void dfs(int x, int sum, int y, int fm) {
	if (x == y) {
		ans += sum * 2;
		return;
	}
	for (int i : b[x]) {
		if (i == fm) {
			for (int j = 1; j <= k[i]; j++) {
				vis[a[i][j]] = 1;
				dfs(j, sum, y, fm);
				vis[a[i][j]] = 0;
			}
		} else {
			for (int j = 1; j <= k[i]; j++) {
				if (vis[a[i][j]])
					continue;
				vis[a[i][j]] = 1;
				dfs(j, sum + 1, y, fm);
				vis[a[i][j]] = 0;
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			b[a[i][j]].push_back(i);
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		ans = w[x] + w[y] + 2;
		vis[x] = 1;
		dfs(x, 0, y, -1);
		vis[x] = 0;
		cout << ans << endl;
	}


	return 0;
}
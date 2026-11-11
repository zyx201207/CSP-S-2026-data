#include <bits/stdc++.h>
using namespace std;

struct node {
	int sum, a[50005], c[50005];
} k[505];

struct st {
	int x, y;
};
int qu, n, m, d, q, w[500005];
bool vis[500005];
vector<st>v[500005];
long long ans;

void dfs(int st, int en, long long cnt, int lx) {
	if (st == en) {
		ans = min(ans, cnt);
		return;
	}
	if (cnt > ans)
		return;
	for (int i = 0; i < v[st].size(); i++) {
		if (lx == v[st][i].x)
			continue;
		for (int j = 1; j <= k[v[st][i].x].sum; j++) {
			if (vis[k[v[st][i].x].a[j]])
				continue;
			vis[k[v[st][i].x].a[j]] = true;
			cnt += (k[v[st][i].x].c[v[st][i].y] + k[v[st][i].x].c[k[v[st][i].x].a[j]]);
			if (lx == k[v[st][i].x].c[v[st][i].y])
				cnt -= 2 * k[v[st][i].x].c[v[st][i].y];
			dfs(k[v[st][i].x].a[j], en, cnt, k[v[st][i].x].c[v[st][i].y]);
			cnt -= (k[v[st][i].x].c[v[st][i].y] + k[v[st][i].x].c[k[v[st][i].x].a[j]]);
			vis[k[v[st][i].x].a[j]] = false;
			if (lx == k[v[st][i].x].c[v[st][i].y])
				cnt += 2 * k[v[st][i].x].c[v[st][i].y];
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> qu >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i].sum;
		for (int j = 1; j <= k[i].sum; j++)
			cin >> k[i].a[j] >> k[i].c[j], v[k[i].a[j]].push_back({i, j});
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		ans = 1e18;
		vis[x] == true;
		dfs(x, y, 0, 0);
		vis[x] == false;
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxm = 5e5 + 10;
int ans;
bool vis[maxm];

struct node2 {
	int w, subsum;
	int sub[505];
} stat[maxm];

struct node1 {
	int ki, a[maxm], t[maxm];
} road[505];

void dfs(int from, int to, int usetime) {
	for (int i = 1; i <= road[from].ki; i++) {
		if (road[from].a[i] == to) {
			ans = min (ans, usetime + stat[road[from].a[i]].w  + road[from].t[i]);
			return;
		}
	}
	for (int i = 1; i <= road[from].ki; i++) {
		if (vis[road[from].a[i]])
			continue;
		int nowsta = road[from].a[i];
		usetime += road[from].t[i];
		if (usetime > ans)
			return;
		for (int i = stat[nowsta].sub[1]; i <= stat[nowsta].subsum; i++) {
			dfs(stat[nowsta].sub[i], to, usetime + road[stat[nowsta].sub[i]].t[nowsta]);
		}
	}
}

int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	ios :: sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	ans = INT_MAX;
	int c, n, m, d, q;
//	cin >> c >> n >> m >> d >> q;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d", &stat[i].w);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &road[i].ki);
		for (int j = 1; j <= road[i].ki; j++) {
			scanf("%d%d", &road[i].a[j], &road[i].t[j]);
			stat[road[i].a[j]].sub[++stat[road[i].a[j]].subsum] = i;
		}
	}
	int xr, yr;
	scanf("%d%d", &xr, &yr);
	for (int i = stat[xr].sub[1]; i <= stat[xr].subsum; i++) {
		dfs (xr, yr, road[stat[xr].sub[i]].t[stat[xr].sub[i]] + stat[xr].w);
	}
	printf("%d", &ans);
	return 0;
}

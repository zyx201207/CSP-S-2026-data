#include <bits/stdc++.h>
using namespace std;
#define maxn 505
#define maxm 5000005
#define maxd 25

int c, n, m, d, Q, cnt, dot;
int h[maxm], to[maxm], nxt[maxm], val[maxm], a[maxm], t[maxm];
int W[maxm];
long long dis[maxm], ans = -1;
bool vis[maxm];

void add(int u, int v, int w) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = h[u];
	val[cnt] = w;
	h[u] = cnt;
}


long long dj(int begining, int ending) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[begining] = 0, ans = -1;
	q.push({0, begining});
	while (!q.empty()) {
		int fir = q.top().second;
		q.pop();
		if (fir == ending) {
			if (ans == -1)
				ans = dis[fir];
			else
				ans = min(ans, dis[fir]);
			continue;
		}
		if (vis[fir])
			continue;
		vis[fir] = 1;
		for (int i = h[fir]; i; i = nxt[i]) {
			int v = to[i], w = val[i];
			if (dis[v] > dis[fir] + w) {
				dis[v] = dis[fir] + w;
				q.push({dis[v], v});
			}
		}
	}
	return ans;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &Q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &W[i]);
	}
	cnt = 0, dot = m;
	int k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			scanf("%d%d", &a[j], &t[j]);
		}
		for (int j = 1; j <= k; j++) {
			dot++;
			add(dot, a[j], t[j]);
			add(a[j], dot, t[j]);
			if (j != k) {
				add(dot, dot + 1, 0);
				add(dot + 1, dot, 0);
			}
		}
	}
	while (Q--) {
		int begining, ending;
		scanf("%d%d", &begining, &ending);
		printf("%lld\n", dj(begining, ending) + W[begining] + W[ending]);
	}
	return 0;
}

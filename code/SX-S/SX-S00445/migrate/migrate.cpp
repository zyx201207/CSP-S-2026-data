#include <bits/stdc++.h>
#define maxn 2000006
using namespace std;
long long c, t, n, d, to[maxn], nxt[maxn], h[maxn], cnt, dis[maxn], num[maxn];
long long x[maxn], all;
bool vis[maxn];

void add(int u, int v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = h[u];
	h[u] = cnt;
};

long long dj(long long begining, long long ending) {
	int ans = 0;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > >
	q;
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	memset(num, 0, sizeof num);
	dis[begining] = 0, num[begining] = 1;
	q.push({0, begining});
	while (!q.empty()) {
		long long fir = q.top().second;
		q.pop();
		if (num[fir] > 2)
			continue;
		if (num[fir] == 2) {
			ans++;
		}

		for (int i = h[fir]; i; i = nxt[i]) {
			int v = to[i];
			if (dis[v] > dis[fir] + 1) {
				dis[v] = dis[fir] + 1;
				q.push({dis[v], v});
				num[v] = num[fir];
			} else {
				if (dis[v] == dis[fir] + 1) {
					num[v] += num[fir];
				}
			}
		}
	}
	return ans;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t--) {
		memset(to, 0, sizeof to);
		memset(nxt, 0, sizeof nxt);
		memset(h, 0, sizeof h);
		cnt = 0, all = 0;
		memset(x, 0, sizeof x);
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= d) {
					add(i, j);
				} else
					break;
			}
		}
		for (int i = 1; i < n; i++) {
			all += dj(i, n);
		}
		printf("%lld\n", all);
	}
	return 0;
}

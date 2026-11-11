#include <bits/stdc++.h>
using namespace std;
#define maxm 1050
#define maxn 520
#define ll long long
#define inf 1000000000000050
int c;
int m, n, d, qus;
ll w[maxm];
int k[maxn];

struct lin {
	vector<int>a;
	vector<ll>t;
} lx[maxn];

struct edge {
	int to, nxt;
	ll val;
} e[maxm * 40];
int h[maxm];
int cnt;

void add(int u, int v, ll wi) {
	e[++cnt].nxt = h[u];
	e[cnt].to = v;
	e[cnt].val = wi;
	h[u] = cnt;
}
ll dis[maxm];

struct node {
	int ps;
	ll ds;
	friend bool operator < (const node &x, const node &y) {
		return x.ds > y.ds;
	}
} tmp;
priority_queue<node>q;
bool vis[maxm];

void Dijkstra(int st) {
	for (int i = 1; i <= m; i++) {
		vis[i] = 0;
		dis[i] = inf;
	}
	dis[st] = 0;
	tmp.ds = 0;
	tmp.ps = st;
	q.push(tmp);
	while (!q.empty()) {
		int u = q.top().ps;
		ll td = q.top().ds;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (int i = h[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			ll wi = e[i].val;
			if (dis[v] > td + wi) {
				dis[v] = td + wi;
				tmp.ds = dis[v];
				tmp.ps = v;
				q.push(tmp);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c;
	cin >> n >> m >> d >> qus;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	int ta;
	ll tt;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];

		for (int j = 1; j <= k[i]; j++) {
			cin >> ta >> tt;
			lx[i].a.push_back(ta);
			lx[i].t.push_back(tt);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k[i]; j++) {
			for (int p = 0; p < k[i]; p++) {
				if (j == p)
					continue;
				add(lx[i].a[j], lx[i].a[p], lx[i].t[j] + lx[i].t[p]);
				add(lx[i].a[p], lx[i].a[j], lx[i].t[j] + lx[i].t[p]);
			}
		}
	}
	for (int i = 1; i <= qus; i++) {
		int x, y;
		cin >> x >> y;
		Dijkstra(x);
		cout << dis[y] + w[x] + w[y] << '\n';
	}
	return 0;
}
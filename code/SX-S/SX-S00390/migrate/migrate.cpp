#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+5;
int n;
ll d;
ll a[N];
int dis[N];
int f[N];
bool v[N];
int h[N], otto;

struct edge {
	int u, v, ne;
} e[2 * N];

void add(int u, int v) {
	e[otto].u = u;
	e[otto].v = v;
	e[otto].ne = h[u];
	h[u] = otto++;
}

struct node {
	int id;
	ll d;
	bool operator <(const node &a) const {
		return a.d < d;
	}
};
priority_queue<node>q;

void Dij(int s) {
	memset(dis, 0x3f, sizeof dis);
	memset(v, 0, sizeof v);
	memset(f, 0x3f, sizeof f);
	q.push({s, 0});
	dis[s] = 0;
	while (!q.empty()) {
		int u = q.top().id, dd = q.top().d;
		q.pop();
		if (v[u]) {
			continue;
		}
		v[u] = 1;
//		cout << u << 'a' << endl;
		for (int i = h[u]; i != -1; i = e[i].ne) {
			int v = e[i].v;
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				f[v] = 1;
				q.push({v, dis[v]});
			} else if (dis[v] == dis[u] + 1) {
				f[v]++;
			}
		}
	}
}

void solve() {
	memset(h, -1, sizeof h);
	otto = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; i + j <= n && a[i + j] - a[i] <= d; j++) {
			add(i, i + j);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		Dij(i);
		for (int j = 1; j <= n; j++) {
//			cout << j << ' ' << dis[j] << endl;
			if (f[j] == 2)
				ans++;
		}
	}
	cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) {
		solve();
	}


	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

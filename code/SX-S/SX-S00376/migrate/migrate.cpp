#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
	int to, w;
	bool operator<(const Node &b) const {
		return w > b.w;
	}
};

const int N = 2e6+9;
vector<Node>v[N];
ll dis1[N], dis2[N], dis3[N], ans;
int n, m;
ll a[N];

void dijkstra(int s) {
	memset(dis1, 0x3f, sizeof(dis1));
	memset(dis2, 0x3f, sizeof(dis2));
	memset(dis3, 0x3f, sizeof(dis3));
	priority_queue<Node>q;
	q.push({s, 0});
	dis1[1] = 0;
	while (!q.empty()) {
		Node u = q.top();
		q.pop();
		if (u.w > dis3[u.to])
			continue;
		for (auto x : v[u.to]) {
			if (u.w + x.w < dis1[x.to]) {
				dis3[x.to] = dis2[x.to];
				dis2[x.to] = dis1[x.to];
				dis1[x.to] = u.w + x.w;
				q.push({x.to, dis1[x.to]});
				q.push({x.to, dis2[x.to]});
				q.push({x.to, dis3[x.to]});
			} else if (u.w + x.w < dis2[x.to]) {
				dis3[x.to] = dis2[x.to];
				dis2[x.to] = u.w + x.w;
				q.push({x.to, dis2[x.to]});
				q.push({x.to, dis3[x.to]});
			} else if (u.w + x.w < dis3[x.to]) {
				dis3[x.to] = u.w + x.w;
				q.push({x.to, dis3[x.to]});
			}
		}
	}
	for (int i = s + 1; i <= n; i++) {
		if (dis1[i] == dis2[i] && dis1[i] != dis3[i]) {
			ans++;
			//cout << s << ' ' << i << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int ID, T;
	cin >> ID >> T;
	while (T--) {
		ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			v[i].clear();
		ll mi = 1e18, ma = -1e18;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			mi = min(mi, a[i]);
			ma = max(ma, a[i]);
		}
		bool s = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] - mi <= m && ma - a[i] <= m) {
				s = 1;
				break;
			}
		}
		if (s == 1) {
			cout << 0 << '\n';
			continue;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (abs(a[j] - a[i]) <= m) {
					v[i].push_back({j, 1});
					v[j].push_back({i, 1});
				}
			}
		}
		for (int i = 1; i <= n; i++)
			dijkstra(i);
		cout << ans << '\n';
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
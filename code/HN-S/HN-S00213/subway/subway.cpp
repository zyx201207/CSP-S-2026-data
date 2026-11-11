#include<bits/stdc++.h>
#define pii pair<int, int> 
#define ls(x) x<<1
#define rs(x) x<<1|1
#define endl '\n'

using namespace std;

const int M = 5e5 + 10;
const int N = 510;
const int MM = 2e4 + 10;

vector<pii> g[M]; 

int c, n, m, d, q, ans;
int w[N], a[N], t[MM][N], dist[MM][N];
bool vis[MM][N];
map<int, int> mp[M];

struct node{
	int val, id, op;
	bool operator < (const node &x) const{
		return val > x.val;
	}
};

int get(int st, int ed) {
	priority_queue<node> q;
	q.push({0, st, 0});
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, 0, sizeof vis);
	dist[st][0] = 0;
	while (!q.empty()) {
		int u = q.top().id;
		int op = q.top().op;
		int val = q.top().val;
		q.pop();
		if (vis[u][op]) continue;
		else vis[u][op] = 1;
		for (auto tmp : g[u]) {
			int v = tmp.first;
			int tp = tmp.second;
			if (tp == op) {
				dist[v][op] = val;
				q.push({dist[v][op], v, op});
			}
			else {
				int w = 0;
				if (op == 0) {
					w = t[u][tp];
				}
				else {
					w = t[u][op] + t[u][tp];
				}
				if (dist[v][tp] > dist[u][op] + w) {
					dist[v][tp] = dist[u][op] + w;
					q.push({dist[v][tp], v, tp});
				}
			}
		}
	}
	int res = 0x3f3f3f3f;
	for (int i = 1; i <= n; ++i) {
		if (dist[ed][i] == 0x3f3f3f3f) continue;
		res = min(res, dist[ed][i] + t[ed][i]);
	}
	return res;
}	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			int x;
			cin >> a[j] >> x;
			t[a[j]][i] = x;
			if (j > 1) {
				g[a[j]].push_back({a[j - 1], i});
				g[a[j - 1]].push_back({a[j], i});
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + get(x, y) << endl;
	}
	return 0;
}

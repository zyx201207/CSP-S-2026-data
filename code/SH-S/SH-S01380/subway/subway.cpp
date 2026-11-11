#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500009, M = 509, INF = 2e18;

struct node {
	int to, w;
};
bool v[N];
long long c, n, m, tt, qq, w[N];
int a[N], t[N];
vector <node> vec[N];
vector <node> e[N];
long long d[M][M];
priority_queue <int> q;
void dij(int x) {
	while (!q.empty()) q.pop();
	q.push(x); d[x][x] = 0;
	for (int i = 0; i < M; ++ i) v[i] = false;
	while (!q.empty()) {
		int u= q.top();  q.pop();
		if (v[u]) continue; v[u] = true;
		for (int g = 0;g < e[u].size(); ++ g) {
			int v = e[u][g].to, w = e[u][g].w;
			if (d[x][v] > d[x][u] + w) {
				d[x][v] = d[x][u] + w;
				q.push(v);
			}
		}
	}
}


signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m>> tt >> qq;
	for (int i = 1;i <= m; ++ i) cin >> w[i];
	for (int i = 1; i <= m; ++ i)
		for (int j = 1; j <= m; ++ j) d[i][j] = INF;
	for (int i = 1; i <= n; ++ i) {
		int k;cin >> k;
		for (int j = 1; j <= k; ++ j) {
			cin >> a[j] >> t[j];
			vec[a[j]].push_back((node) {i, t[j]});
		}
	}
	for (int i = 1; i <= m; ++ i) {
		for (int j = 0; j < vec[i].size(); ++ j)
			for (int k = j + 1;k < vec[i].size(); ++ k) {
				int u = vec[i][j].to, v = vec[i][k].to, w = vec[i][j].w + vec[i][k].w;
				e[u].push_back((node) {v, w});
				e[v].push_back((node) {u, w});
			}
	}
	for (int i = 1; i <= n; ++ i) dij(i);
	for (int i = 1;i <= qq; ++ i) {
		int x, y; cin >> x >> y;
		int ans = INF;
		for (int j = 0;j < vec[x].size(); ++ j)
			for (int k = 0; k < vec[y].size(); ++ k) {
				node u = vec[x][j], v = vec[y][k];
				ans = min(ans, w[x] + w[y] + u.w + v.w + d[u.to][v.to]);
				//cout << j << " " << k << " " << u.to << " " << v.to << endl;
			}
		cout << ans << endl;
	}
/*
think of me
think of me fondly
when you say goodbye
passing all the subtests in 40min
recalling the days when practing dij for no obvious reasons, but for the admiration of this algorizm's elegance
from zj to efz
the sense of pride and achievement fade slowly
but the passion
has been with me tiil TODAY.love OI
AFO
*/
	return 0;
}



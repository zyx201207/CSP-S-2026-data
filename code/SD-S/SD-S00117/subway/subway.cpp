#include <bits/stdc++.h>
#define M 500010
#define N 510
#define int long long
using namespace std;
typedef pair <int, int> PII;
const int INF = 1e18;
int c, n, m, d, q, w[M], k[N];
int dis[N][N];
vector <int> a[N], t[N];
vector <PII> b[M];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) {
			int tmp1, tmp2; cin >> tmp1 >> tmp2;
			a[i].push_back(tmp1); t[i].push_back(tmp2);
			b[tmp1].push_back({i, tmp2});
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j) dis[i][j] = INF;
	for(int id = 1; id <= m; id++) {
		int sz = b[id].size();
		for(int i = 0; i < sz; i++)
			for(int j = i + 1; j < sz; j++) {
				int u = b[id][i].first, v = b[id][j].first;
				int ut = b[id][i].second, vt = b[id][j].second;
				dis[u][v] = dis[v][u] = min(dis[u][v], ut + vt);
			}
	}
	for(int l = 1; l <= n; l++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][l] + dis[l][j]);
	while(q--) {
		int u, v; cin >> u >> v;
		int ans = INF;
		for(auto i : b[u]) for(auto j : b[v])
			ans = min(ans, dis[i.first][j.first] + i.second + j.second);
		cout << ans + w[u] + w[v] << '\n';
	}
	return 0;
}
/*
有点坏，考前忘记打一遍floyd了
ber这个反斜杠怎么在这阴间位置，被坑两回了
我想要lambda表达式！！真不方便 
*/ 

#include <bits/stdc++.h>

using namespace std;
const int T = 500;
const int N = 5e5;
const int inf = 1e9;
const int M = 1e6;
int c, n, m, d, Q;
typedef pair<int,int> PII;
vector<PII> G[M + 5];
int w[N + 5];
int t[T + 5][N + 5], a[T + 5][N + 5];
int v[N + 5], dis[N + 5];
int DDis[N + 5], vis[N + 5], ans = inf;

queue<PII> q;
void dfs (int st, int ed){
	memset (DDis, 0x3f, sizeof DDis);
	memset (vis, 0, sizeof vis);
	DDis[st] = w[st], vis[st] = 1;
	q.push({st, w[st]});
	while (!q.empty()){
		PII t = q.front();
		q.pop();
		int uu = t.first;
		if (vis[uu]) continue;
 		vis[uu] = 1;
		if (uu == ed){
			ans = min (ans, t.second);
			return ;
		}
		for (auto i : G[uu]){
			int vv = i.first;
			int ww = i.second;
			if (DDis[uu] > DDis[vv] + ww + w[vv]){
				DDis[uu] = DDis[vv] + ww + w[vv];
				q.push({vv, DDis[uu]});
			}
 		} 
	}
}
signed main(){
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; ++ i){
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++ i){
		int ki;
		cin >> ki;
		for (int j = 1; j <= ki; ++ j){
			cin >> v[j] >> dis[j];
			if (i > 1){
				G[v[j]].push_back({v[j - 1], dis[j]});
				G[v[j - 1]].push_back({v[j], dis[j]});
			}
		}
	}
	while (Q --){
		int xr, yr;
		cin >> xr >> yr;
		ans = inf;
		dfs (xr, yr);
		cout << ans << "\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

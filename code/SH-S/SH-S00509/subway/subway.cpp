#include<bits\stdc++.h>
using namespace std;
#define int long long
#define c first
#define u second
const int INF = 0x3f3f3f3f;
const int N = 500 + 10, M = 5e5 + 500 + 10, Q = 1e5 + 10;
int n, m, c, d, q;
int w[M], k[N];
struct edge{
	int v;
	int cst;
};
vector<edge> s[M];
int us[Q], vs[Q];
int vis[M];
int solve(int u, int v){
	memset(vis, INF, sizeof(vis));
	priority_queue<pair<int, int>> qu;
	qu.push({0, u});
	while (qu.size()){
		auto now = qu.top();
		qu.pop();
		if (now.c > vis[now.u]) continue;
		for (auto nxt : s[now.u]){
			if (now.c + nxt.cst < vis[nxt.v]){
				vis[nxt.v] = now.c + nxt.cst;
				qu.push({now.c + nxt.cst, nxt.v});
			}
		}
	}
	return vis[v];
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		if (k[i] == 2){
			int a1, t1, a2, t2;
			cin >> a1 >> t1 >> a2 >> t2;
			s[a1].push_back({a2, t1+t2});
			s[a2].push_back({a1, t1+t2});
		}
		else{
				for (int j = 1; j <= k[i]; j++){
				int a, t;
				cin >> a >> t;
				s[(int)5e5 + i].push_back({a, t});
				s[a].push_back({(int)5e5 + i, t});
			}
		}
	}
	for (int i = 1; i <= q; i++){
		cin >> us[i] >> vs[i];
	}
	for (int i = 1; i <= q; i++){
		int ans = solve (us[i], vs[i]);
		ans += w[us[i]] + w[vs[i]];
		cout << ans << '\n';
	}
	return 0;
}

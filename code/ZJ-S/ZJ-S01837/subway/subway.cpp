#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500001], t, k[501], u[500001], v[500001], x ,y, vis[2][500001];
struct node{
	int x, v, t;
	bool operator < (const node &a) const {
		return x > a.x;
	}
}o;
vector<node>g[2][500001];
priority_queue<node>s, S;
int main(){
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	scanf ("%d%d%d%d%d" ,&c ,&n ,&m ,&d ,&q);
	for (int i = 1;i <= m;i ++){
		scanf ("%d" ,&w[i]);
		g[1][i].push_back({0, i, w[i]});
		g[0][i].push_back({1, i, w[i]});
	}
	for (int i = 1;i <= n;i ++){
		scanf ("%d" ,&k[i]);
		for (int j = 1;j <= k[i];j ++){
			scanf ("%d%d" ,&u[j] ,&v[j]);
		}
		for (int j = 1;j <= k[i];j ++){
			for (int l = 1;l <= k[i];l ++){
				if (j != l){
					g[0][u[j]].push_back({0, u[l], v[j] + v[l]});
					g[0][u[l]].push_back({0, u[j], v[l] + v[j]});
				}
			}
		}
	}
	while (q --){
		memset(vis, 0x3f, sizeof(vis));
		scanf ("%d%d" ,&x ,&y);
		s = S;
		s.push({1, x, 0});
		while (s.size()){
			o = s.top();
			s.pop();
			if (vis[o.x][o.v] <= o.t){
				continue;
			}
			vis[o.x][o.v] = o.t;
			for (int i = 0;i < g[o.x][o.v].size();i ++){
				s.push({g[o.x][o.v][i].x, g[o.x][o.v][i].v, o.t + g[o.x][o.v][i].t});
			}
		}
		printf ("%d\n" ,vis[1][y]);
	}
	return 0;
}

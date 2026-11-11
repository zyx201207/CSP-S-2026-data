#include <bits/stdc++.h>
using namespace std;
#define pii pair <int, int>
int v[500005];
int a[505][50005];
int t[505][50005];
int vis[500005];
int anstime;
int ansxl;
queue <pii> q; // first 位置 second 时间 
vector <pii> g[500005];//线路 线路上的位置 
void dij(int xx, int yy){
	memset(vis, 0x3f, sizeof(vis));
	q.push({xx, 0});
	vis[xx] = 0;
	while(!q.empty()){
		pii u = q.front();
		q.pop();
		if (vis[u.first] < u.second){
			continue;
		}
		for (int j = 0; j < int(g[u.first].size()); j++){
			int v1 = g[u.first][j].first;
			for (int i = 1; i <= a[v1][0]; i++){
				if (u.first == a[v1][i]){
					continue;
				}
				int ntime = vis[u.first] + t[v1][i] + t[v1][g[u.first][j].second];
				if (ntime >= vis[a[v1][i]]){
				//	cout << vis[a[v1][i]] << ' ';
					continue;
				} 
				vis[a[v1][i]] = ntime;
				q.push({a[v1][i], ntime});
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, p;
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++){
		scanf("%d", &v[i]);
	}
	for (int i = 1; i <= n; i++){
		int k;
		scanf("%d", &k);
		a[i][0] = k;
		for (int j = 1; j <= k; j++){
			scanf("%d%d", &a[i][j],&t[i][j]);
			g[a[i][j]].push_back({i,j});
		}
		
	}
	while(p--){
		int x,y;
		scanf("%d%d", &x,&y);
		dij(x,y);
		cout << vis[y] + v[x] + v[y] << '\n';
	}
	return 0;
}
//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2

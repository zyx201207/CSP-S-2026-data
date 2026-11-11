#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int inf = 0x3f3f3f3f;
int c, n, m, d, q, vis[N], w[N];
long long dis[N];
int t[510][N];
vector<int>a[510];
vector< pair<int, int> >g[N];
struct node{
	int v, val, way;
	bool friend operator < (node x, node y){
		return x.val > y.val;
	}
};
void dij(int s){
	for(int i = 1; i <= m; i++){
		dis[i] = inf;
		vis[i] = 0;
	}
	priority_queue<node> q;
	
	int W = g[s][0].second;
	dis[s] = t[W][s];
	//cout << W << endl;
	q.push({s, dis[s], W});
	while(!q.empty()){
		int u = q.top().v;
		int way = q.top().way;
		q.pop();
		if(vis[u])continue;
		vis[u] = 1;
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i].first;
			int ww = g[u][i].second;
			if(ww != way){
				if(dis[u] + t[ww][u] + t[way][u] < dis[v]){
					//cout << t[way][u] << ' ' << t[ww][u] << endl;
					dis[v] = dis[u] + t[ww][u] + t[way][u];
					//cout << dis[v] << endl;
					q.push({v, dis[v], ww});
				}
			}
			else {
				//cout << dis[u] + t[way][v] << endl;
				if(dis[u] + t[way][v] < dis[v]){
					dis[v] = dis[u] + t[way][v];
					//cout << dis[v] << endl;
					q.push({v, dis[v], way});
				}
			}
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 1; i <= n; i++){
		int k; scanf("%d", &k);
		for(int j = 1; j <= k; j++){
			int v; scanf("%d", &v);
			a[i].push_back(v);
			scanf("%d", &t[i][v]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int u = 0; u < a[i].size(); u++){
			for(int v = u + 1; v < a[i].size(); v++){
				g[a[i][u]].push_back({a[i][v], i});
			}
		}
	}
	
	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		dij(x);
		printf("%d\n", dis[y] + w[x] + w[y]);
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

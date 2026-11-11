#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = INT_MAX;
int head[500010], tot = 0;
struct node{
	int x, y;
};
int c, n, m, d, q;
vector<vector<int>> g;
vector<node> arr;
vector<int> w;
vector<int> path;
void dij(int s, int t){
	queue<int> qq;
	vector<int> dist(m + 5, INF);
	vector<int> vis(m + 5);
	int x = 0, nx = -1;
	qq.push(s);
	dist[s] = 0;
	while(!qq.empty()){
		int u = qq.front();
		qq.pop();
		for(int v : g[u]){
			if(v == s) continue;
			if(dist[v] > dist[u] + 1){
				dist[v] = dist[u] + 1;
				qq.push(v);
				if(nx != x) path.push_back(v), nx = x;
				vis[v] = x;
			}
		}
		x++;
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	g.resize(m + 5, {});
	arr.resize(m + 5, {0, 0});
	w.resize(m + 5);
	vector<vector<int>> t(n + 5, vector<int> (m + 5, 0));
	for(int i = 1; i <= m; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++){
		int k;
		scanf("%d", &k);
		int aa;
		scanf("%d%d", &aa, &t[i][1]);
		arr[aa] = {i, 1};
		for(int j = 2; j <= k; j++){
			int a;
			scanf("%d%d", &a, &t[i][j]);
			g[aa].push_back(a);
			g[a].push_back(aa);
			arr[a] = {i, j};
		}
	}
	while(q--){
		int s, tt;
		scanf("%d%d", &s, &tt);
		dij(s, tt);
		int cost = 0;
		for(int i = 0; i < path.size(); i++){
			int ii = arr[path[i]].y;
			int jj = arr[path[i + 1]].x;
			cost += t[ii][jj];
		}
		printf("%d\n", cost);
	}
	return 0;
}
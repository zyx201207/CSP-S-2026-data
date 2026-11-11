#include<bits/stdc++.h>
using namespace std;
const int N = 510, M = 5e5+10, inf = 1e9;
struct node{
	int to, w;
};
struct edge{
	int to, w;
	bool operator < (const edge &b) const{
		return w < b.w;
	}
};
int k[N], w[M];vector<node>e[M];
int c, n, m, d, qp;
int bfs(int sx, int fx){
	vector<int>vis(M, 0);
	vector<int>dis(M, 0);
	priority_queue<edge> q;
	q.push({sx, 0});
	int num = 0;
	while(q.size()){
		int x = q.top().to;
		q.pop();
		for(auto u:e[x]){
			int nx = u.to, nw = u.w;
			if(dis[nx] > dis[x]+nw){
				dis[nx] = dis[x]+nw;
				if(!vis[nx]){
					vis[nx] = 1;
					q.push({nx, dis[nx]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >>n >> m >> d >>qp;
	for(int i = 1;i <= m;i ++){cin >> w[i];}
	for(int i = 1;i <= n;i ++){
		cin >> k[i];
		if(k[i] == 1){
			int x, y;
			cin >>x >> y;
		}
		if(k[i] == 2){
			int u, v, w1, w2;
			cin >> u >> w1 >> v >>w2;
			e[u].push_back({v, w1+w2});
		}
	}
	while(qp--){
		int x, y;
		cin >> x >> y;
		int sum = w[x]+w[y];
		cout << sum+bfs(x, y) << '\n';;
		
	}
	return 0;
} 

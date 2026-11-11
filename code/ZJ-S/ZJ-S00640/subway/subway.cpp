#include<bits/stdc++.h>
using namespace std;
struct Node{
	pair<int, int> pos;
	long long val;
	bool operator < (const Node &other) const {
		return val > other.val;
	}
};
struct Edge{
	pair<int, int> to;
	int w;
};
int c, n, m, d, q, r[500010], k[510], a[510][1010], t[510][1010];
long long dist[510][1010];
bool vis[510][1010];
vector<Edge> edges[510][1010];
priority_queue<Node> pq;
vector<pair<int, int> > v[500010];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++){
		scanf("%d", &r[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &k[i]);
		for(int j = 1; j <= k[i]; j++){
			scanf("%d%d", &a[i][j], &t[i][j]);
			v[a[i][j]].push_back({i, j});
		}
		for(int j = 1; j <= k[i]; j++){
			for(int l = j + 1; l <= k[i]; l++){
				edges[i][j].push_back({{i, l}, 0});
			}
		}
	}	
	for(int i = 1; i <= m; i++){
		if(!v[i].empty()){
			int sz = (int)v[i].size();
			for(int j = 0; j < sz; j++){
				for(int l = 0; l < sz; l++){
					if(j != l){
						edges[v[i][j].first][v[i][j].second].push_back({{v[i][l].first, v[i][l].second}, t[v[i][j].first][v[i][j].second] + t[v[i][l].first][v[i][l].second]});
					}
				}
			}
		}
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= k[i]; j++){
//			cout << i << " " << j << "********\n";
//			for(auto y : edges[i][j]){
//				cout << y.to.first << " " << y.to.second << " " << y.w << endl;
//			}
//		}
//	}
	for(int S, E; q--; ){
		scanf("%d%d", &S, &E);
		int sz = (int)v[S].size();
		long long ans = 1LL << 60;
		for(int i = 0; i < sz; i++){
			while(!pq.empty()){
				pq.pop();
			}
			memset(vis, 0, sizeof(vis));
			memset(dist, 0x3f, sizeof(dist));
			for(int j = 1; j <= v[S][i].second; j++){
				dist[v[S][i].first][j] = t[v[S][i].first][j];
				pq.push({{v[S][i].first, j}, t[v[S][i].first][j]});
			}
			long long minn = 1LL << 60;
			while(!pq.empty()){
				pair<int, int> x = pq.top().pos;
				pq.pop();
//				cout << "**" << x.first << " " << x.second << " " << dist[x.first][x.second] << endl;
				if(vis[x.first][x.second]){
					continue;
				}
				vis[x.first][x.second] = 1;
				if(a[x.first][x.second] == E){
					minn = min(minn, dist[x.first][x.second] + t[x.first][x.second]);
					continue;
				}
				for(auto y : edges[x.first][x.second]){
					if(dist[y.to.first][y.to.second] > dist[x.first][x.second] + y.w){
						dist[y.to.first][y.to.second] = dist[x.first][x.second] + y.w;
						pq.push({{y.to.first, y.to.second}, dist[y.to.first][y.to.second]});
					}
				}
			}
//			cout << endl;
			ans = min(ans, minn);
		}
		printf("%lld\n", ans + r[S] + r[E]);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int u, v;
};
int c, n, m, d, q, w[1005], a[505][1005], t[505][1005], k, x, y, dist[1005];
bool vis[1005];
vector<Node> G[500005];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int l = 1; l <= n; l++){
		cin >> k;
		for(int i = 1; i <= k; i++){
			cin >> a[l][i] >> t[l][i];
		}
		for(int i = 1; i <= k; i++){
			for(int j = i; j <= k; j++){
				if(i != j){
					G[i].push_back({j, t[l][i] + t[l][j]});
					G[j].push_back({i, t[l][j] + t[l][i]});
				}
			}
		}
	}
	while(q--){
		cin >> x >> y;
		queue<int> Q;
		memset(dist, 0x3f, sizeof(dist));
		for(int i = 1; i <= m; i++) vis[i] = false;
		Q.push(x);
		dist[x] = 0;
		while(!Q.empty()){
			int p = Q.front();
			Q.pop();
			for(int i = 0; i < G[p].size(); i++){
				if(dist[G[p][i].u] > dist[p] + G[p][i].v){
					dist[G[p][i].u] = dist[p] + G[p][i].v;
					if(!vis[G[p][i].u]){
						Q.push(G[p][i].u);
						vis[G[p][i].u] = true;
					}
				}
		    }
		}
		cout << w[x] + w[y] + dist[y] << endl;
	}
	return 0;
}

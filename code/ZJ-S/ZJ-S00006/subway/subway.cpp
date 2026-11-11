#include<bits/stdc++.h>

using namespace std;

typedef pair<int, long long> PIL;

int sz[505010];

int V1[22][505010];
long long V2[22][505010];

//vector<PIL> V[550010];

long long a[500010];
long long G[510][510];
long long dis[510][510];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			long long v, w;
			cin >> v >> w;
			V1[++sz[v]][v] = i;
			V2[sz[v]][v] = w;
//			V[v].push_back({i, w});
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dis[i][j] = 1e18;
			G[i][j] = 1e18;
		}
		dis[i][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		int sz1 = sz[i];
		for(int j = 1; j <= sz1; j++){
			for(int k = 1; k <= sz1; k++){
				int v1 = V1[j][i];
				long long w1 = V2[j][i];
				int v2 = V1[k][i];
				long long w2 = V2[k][i];
				if(v1 == v2){
					G[v1][v2] = 0;
					continue;
				}
				G[v1][v2] = min(G[v1][v2], w1 + w2);
				dis[v1][v2] = G[v1][v2];
			}
		}
	}
	for(int k = 1; k <= n; k++){
		int i = 1;
		while(i <= n){
			int j = 1;
			while(j <= n){
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
				j++;
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
				j++;
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
				j++;
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
				j++;
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
				j++;
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
				j++;
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
				j++;
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
				j++;
			}
			i++;
		}
//		for(int i = 1; i <= n; i++){
			
//			for(int j = 1; j <= n; j++){
////				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
//				if(dis[i][j] > dis[i][k] + dis[k][j]){
//					dis[i][j] = dis[i][k] + dis[k][j];
//				}
//			}
//		}
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			cout << dis[i][j] << " ";
//		}
//		cout << "\n";
//	}
	while(q--){
		int u, v;
		cin >> u >> v;
		long long ji = a[u] + a[v];
		long long ret = 1e18;
		int sz1 = sz[u];
		int sz2 = sz[v];
		for(int j = 1; j <= sz1; j++){
			for(int k = 1; k <= sz2; k++){
				int v1 = V1[j][u];
				long long w1 = V2[j][u];
				int v2 = V1[k][v];
				long long w2 = V2[k][v];
				if(ret > dis[v1][v2] + w1 + w2){
					ret = dis[v1][v2] + w1 + w2;
				}
//				ret = min(ret, dis[v1][v2] + w1 + w2);
			}
		}
		cout << ret + ji << "\n";
	}
	
	
	return 0;
}
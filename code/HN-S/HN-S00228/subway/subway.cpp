#include<bits/stdc++.h>
using namespace std;
const int N = 5e2+5, M=5e5+5, QCNT = 1e5+5;
int t[N][M], w[M], p[N];
int c, n, m, d, q;
int dis[N][N];//第i个站台的站厅到第j个站台的站厅的最短路 
map<int, vector<int> > G;//第i个站点，在哪些线路上 
bool check(int t, int l){
	int get = lower_bound(G[t].begin(), G[t].end(), l)-G[t].begin();
	return get!=G[t].size()&&G[t][get]==l;
}
bool zhijie(int s, int t){
	for(int i = 0;i < G[i].size();i++){
		if(check(t, G[s][i])) return 1;
	}
	return 0;
}
int f(int u, int a, int b){
	return t[u][a]+t[u][b];
}
int l[N][N];
void floyed(){
	for(int u = 1;u <= n;u++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j<=n;j++){
				if(i==j) {
					dis[i][j] = 0;
					continue;	
				}
				for(int v = 0;v < min(G[i].size(), G[j].size());v++){
					if(check(j, G[i][v])){//走地铁线路G[i][v] 
						dis[i][j] = min(dis[i][u]+t[u][G[i][v]], dis[i][j]);
					}
				}
			}
		}
	}
}
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway1.in","r", stdin);
	freopen("subway.out", "w", stdout);
	//cout<<1;
	memset(dis, 0x7f, sizeof(dis));
	cin>>n>>m>>d>>q;
	for(int i = 1;i <= n;i++){
		cin>>w[i];
	}
	int k = 0;
	for(int i = 1;i <= n;i++){
		cin>>k;
		int x;
		for(int j = 1;j <= k;j++){
			cin>>x;
			G[x].push_back(i);
			cin>>t[x][i];
		}
	}
	floyed();
	for(int i = 1;i <= q;i++){
		int x, y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
} 

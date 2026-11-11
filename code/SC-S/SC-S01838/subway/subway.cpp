#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ull unsigned long long
using namespace std;

struct to{
	int u,t;
};
const int N=5e5 + 5,M=5e2 + 5,INF=9e18,CMP=1e18;
vector<vector<to>> through(N);
int w[N],k[M],d[M][M],dist[M][M];
bool vis[M];
int c,m,n,mx_through,q;
void dijkstra(int s){
	for(int i=1;i <= m;i++){
		vis[i]=false;
	}
	int u=s;
	for(int i=1;i <= m;i++){
		vis[u]=true;
		int mn=INF,mnnum=0;
		for(int v=1;v <= m;v++){
			if(vis[v]){
				continue;
			}
			dist[s][v]=min(dist[s][v],dist[s][u] + d[u][v]);
			if(dist[s][v] < mn){
				mn=dist[s][v];
				mnnum=v;
			}
		}
		u=mnnum;
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> m >> n >> mx_through >> q;
	for(int i=1;i <= n;i++){
		cin >> w[i];
	}
	for(int i=1;i <= m;i++){
		for(int j=1;j <= m;j++){
			if(i == j){
				d[i][j]=0;
				dist[i][j]=0;
			} else{
				d[i][j]=INF;
				dist[i][j]=INF;
			}
		}
	}
	for(int i=1;i <= m;i++){
		cin >> k[i];
		for(int j=1;j <= k[i];j++){
			int v,c;
			cin >> v >> c;
			through[v].push_back({i,c});
		}
	}
	for(int i=1;i <= n;i++){
		int len=through[i].size();
		for(int j=0;j <= len - 2;j++){
			for(int k=j + 1;k <= len - 1;k++){
				int u=through[i][j].u,v=through[i][k].u;
				int tu=through[i][j].t,tv=through[i][k].t;
				d[u][v]=min(d[u][v],tu + tv);
				d[v][u]=min(d[v][u],tu + tv);
			}
		}
	}
	for(int i=1;i <= m;i++){
		dijkstra(i);
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		int mn=INF;
		int len_x=through[x].size(),len_y=through[y].size();
		for(int i=0;i <= len_x - 1;i++){
			for(int j=0;j <= len_y - 1;j++){
				int u=through[x][i].u,v=through[y][j].u;
				int tu=through[x][i].t,tv=through[y][j].t;
				mn=min(mn,dist[u][v] + tu + tv);
			}
		}
		cout << w[x] + w[y] + mn << endl;
	}
	return 0;
}
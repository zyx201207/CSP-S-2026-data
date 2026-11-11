#include<bits/stdc++.h>
using namespace std;
const int M=5e5+7;
struct ee{
	int v,w;
};
struct node{
	long long dis;
	int u;
	bool operator<(const node& x) const{
		return dis > x.dis;
	}
};
int c,n,m,d,q,w[M],k[M],a[507][M],t[507][M];
long long dis[M];
bool vis[M],f[507][M];
vector<ee> g[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++)
		cin >> w[i];
	for(int i=1; i<=n; i++){
		cin >> k[i];
		for(int j=1; j<=k[i]; j++){
			cin >> a[i][j] >> t[i][j];
			if(f[i][j]) f[i][j] = 0;
			f[i][j] = 1;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<k[i]; j++){
			g[a[i][j+1]].push_back({a[i][j],t[i][j]});
			g[a[i][j]].push_back({a[i][j+1],t[i][j]});
		}
	}
	priority_queue<node> qu;
	while(q--){
		int x,y;
		cin >> x >> y;
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dis[x] = w[x];
		qu.push({w[x],x});
		while(qu.size()){
			int nw = qu.top().u;
			qu.pop();
			if(vis[nw]) continue;
			vis[nw] = 1;
			for(int i=0; i<g[nw].size(); i++){
				int vv=g[nw][i].v;
				long long ww=g[nw][i].w;
				for(int u=1; u<=n; u++){
					for(int v=1; v<=k[u]; v++){
						if(a[u][v] == vv && !f[u][v])
							if(dis[vv] > dis[nw]+ww+t[u][v+1]){
								dis[vv] = dis[nw]+ww+t[u][v+1];
								qu.push({dis[vv],vv});
							}
						else
							if(dis[vv] > dis[nw]+ww){
								dis[vv] = dis[nw]+ww;
								qu.push({dis[vv],vv});
							}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=k[i]; j++){
				if(a[i][j] == y)
					dis[y] += t[i][j];
			}
		}
		cout << dis[y]+w[y] << '\n';
	}
	return 0;
}
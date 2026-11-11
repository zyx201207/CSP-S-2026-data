#include<bits/stdc++.h>
using namespace std;
namespace T2{
	const int M=1e6+10,N=510;
	const long long INF=0x3f3f3f3f3f3f3f3f;
	int c,n,m,d,q;
	long long w[M+N];
	long long dis[N][N];
	struct edge{
		long long v,w;
	};
	vector<edge> e[M+N];
	void solve(){
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		cin >> c >> n >> m >> d >> q;
		for(int i=n+1;i<=n+m;i++) cin >> w[i];
		for(int i=1;i<=n;i++){
			int k,a,t;
			cin >> k;
			for(int j=1;j<=k;j++){
				cin >> a >> t;
				e[i].emplace_back(edge{a+n,t});
				e[a+n].emplace_back(edge{i,t});
			}
		}
//		for(int u=1;u<=n+m;u++){
//			for(int i=0;i<(int)e[u].size();i++) cout << u << ' ' << e[u][i].v << ' ' << e[u][i].w << '\n';
//		}
		memset(dis,0x3f,sizeof(dis));
		for(int i=n+1;i<=n+m;i++){
			for(int j=0;j<(int)e[i].size();j++){
				for(int k=0;k<(int)e[i].size();k++){
					int u=e[i][j].v,v=e[i][k].v;
					long long w=e[i][j].w+e[i][k].w;
					if(u==v) w=0;
					dis[u][v]=min(dis[u][v],w);
					dis[v][u]=min(dis[v][u],w);
//					cout << u << ' ' << v << ' ' << w << '\n';
				}
			}
		}
		for(int x=1;x<=n;x++){
			for(int u=1;u<=n;u++){
				for(int v=1;v<=n;v++){
					dis[u][v]=min(dis[u][v],dis[u][x]+dis[x][v]);
				}
			}
		}
//		for(int u=1;u<=n;u++){
//			for(int v=1;v<=n;v++){
//				cout << dis[u][v] << ' ';
//			}
//			cout << '\n';
//		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin >> x >> y,x+=n,y+=n;
			long long ans=INF;
			for(int j=0;j<e[x].size();j++){
				for(int k=0;k<e[y].size();k++){
					int u=e[x][j].v,v=e[y][k].v,w=e[x][j].w+e[y][k].w;
					ans=min(ans,dis[u][v]+w);
//					cout << u << ' ' << v << ' ' << dis[u][v]+w << '\n';
				}
			}
			cout << ans+w[x]+w[y] << '\n';
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	T2::solve();	
	
	
	
	return 0;
}

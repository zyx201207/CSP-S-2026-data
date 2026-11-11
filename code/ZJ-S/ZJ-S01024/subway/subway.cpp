#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,int>
#define fi first
#define se second
#define N 500050
using namespace std;
ll dis[505][505];
vector<pa>g[N];
int w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int siz;scanf("%d",&siz);
		while(siz--){
			int x,w;scanf("%d%d",&x,&w);
//			cerr<<"2222"<<" "<<i<<" "<<x<<" "<<w<<"\n";
			g[x].push_back(make_pair(i,w));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
			if(i==j)dis[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		int siz=g[i].size();
		for(int x=0;x<siz;x++){
			int u=g[i][x].fi;
			for(int y=x+1;y<siz;y++){
				int v=g[i][y].fi;
				ll w=g[i][x].se+g[i][y].se;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
//				cerr<<"1111111 "<<u<<" "<<v<<" "<<w<<"\n";
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int u,v;scanf("%d%d",&u,&v);
		ll ans=1e18;
		int siz1=g[u].size();
		int siz2=g[v].size();
		for(int x=0;x<siz1;x++){
			int id1=g[u][x].fi;
			for(int y=0;y<siz2;y++){
				int id2=g[v][y].fi;
				ll w=g[u][x].se+g[v][y].se;
				ans=min(ans,w+dis[id1][id2]);
			}
		}
		ans+=w[u];ans+=w[v];
		printf("%lld\n",ans);
	}
	return 0;
}

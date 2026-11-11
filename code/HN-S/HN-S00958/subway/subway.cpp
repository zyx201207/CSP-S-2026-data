#include<bits/stdc++.h>
using namespace std;
int const N = 505,M = 5e5+7;
int c,n,m,d,q,w[M],vis[M],T[M][N];
long long dis[N][N];
struct node{
	int v,w;
};
vector<node> h[M]; //存每个点被哪些线路经过了，并且存一个这条线到这个点的站台的距离 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	memset(dis,0x3f,sizeof(dis));
	for(int u=1;u<=n;u++){
		dis[u][u] = 0;
		int l;scanf("%d",&l);
		for(int i=1;i<=l;i++){
			int a,t;scanf("%d%d",&a,&t);
			if(vis[a]){
				for(node k:h[a]){
					int v = k.v;
					long long w = k.w+t;
					dis[u][v] = min(dis[u][v],w);
					dis[v][u] = min(dis[v][u],w);
				}
			}
			vis[a] = 1;
			h[a].push_back({u,t});
			T[a][u] = t;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int st,ed;cin>>st>>ed;
		long long mn = 1e18;
		for(node i:h[st]){
			int u = i.v;
			for(node j:h[ed]){
				int v = j.v;
				mn = min(mn,(long long)T[st][u]+dis[u][v]+T[ed][v]);
			}
		}
		printf("%lld\n",(long long)w[st]+mn+w[ed]);
	}
	return 0;
}


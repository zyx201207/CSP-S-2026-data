#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pll;
const int N=510,M=5e5+10;
int C,n,m,d,q,dis[N][N],w[M],xlqz[M][25];
int fa[M][25],fas[M],xlxl[M][25],xls[M],hcz[M],t,G[N][N];
vector<pll> g[N];
void dijkstra(int x){
	priority_queue<pll,vector<pll>,greater<pll> > q;
	dis[x][x]=0;
	q.push({dis[x][x],x});
	while(!q.empty()){
		int u=q.top().second,len=q.top().first;
		q.pop();
		for(auto i:g[u]){
			int v=i.first,bq=i.second;
			if(len+bq>=dis[x][v]) continue;
			dis[x][v]=len+bq;
			q.push({dis[x][v],v});
		}
	}
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&C,&n,&m,&d,&q);
	memset(dis,0x3f,sizeof(dis));
	memset(G,0x3f,sizeof(G));
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int zd,bq;
			scanf("%lld %lld",&zd,&bq);
			xlqz[zd][i]=bq;
			fa[zd][++fas[zd]]=i;
			xlxl[zd][++xls[zd]]=i;
			if(xls[zd]>1) hcz[++t]=zd;
		}
	}
	for(int i=1;i<=t;i++){
		int xb=0,zd=hcz[i];
		for(int l=1;l<=xls[zd];l++){
			for(int r=l+1;r<=xls[zd];r++){
				int z=xlxl[zd][l],y=xlxl[zd][r];
				G[z][y]=min(G[z][y],xlqz[zd][y]+xlqz[zd][z]);
				G[y][z]=G[z][y];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!G[i][j]||i==j) continue;
			g[i].push_back({j,G[i][j]});
			g[j].push_back({i,G[j][i]});
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	while(q--){
		int x,y,b=0,ans,da=0x3f3f3f3f3f3f3f3f,zh=0;
		scanf("%lld %lld",&x,&y);
		ans=w[x]+w[y];
		for(int i=1;i<=fas[x];i++){
			for(int j=1;j<=fas[y];j++){
				if(fa[x][i]==fa[y][j]){
					da=min(da,ans+xlqz[x][fa[x][i]]+xlqz[y][fa[y][j]]);
					break;
				}
				da=min(da,ans+dis[fa[x][i]][fa[y][j]]+xlqz[x][fa[x][i]]+xlqz[y][fa[y][j]]);
			}
			if(b) break;
		}
		if(b) printf("%lld\n",ans);
		else printf("%lld\n",da);
	}
	return 0;
}

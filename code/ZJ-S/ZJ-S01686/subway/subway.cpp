#include <bits/stdc++.h>
#define int long long
#define PII pair<long long,long long>
#define fi first
#define se second
using namespace std;
const int N=5e5+10;
const int B=510;
const int INF=0x3f3f3f3f3f3f3f3f;
int cid,n,m,q,d;
vector<PII>e[N];
int vis[B],w[N],dis[B][B];
void A(int u,int v,int w){
	dis[u][v]=min(dis[u][v],w);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;cin>>v>>w;
			e[v].push_back({i,w});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto xx:e[i]){
			for(auto yy:e[i]){
				if(xx.fi==yy.fi) continue;
				A(xx.fi,yy.fi,xx.se+yy.se);
				A(yy.fi,xx.fi,xx.se+yy.se);
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
		int u,v;cin>>u>>v;
		int ans=INF;
		for(auto xx:e[u]){
			for(auto yy:e[v]){
				ans=min(ans,xx.se+yy.se+dis[xx.fi][yy.fi]);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}

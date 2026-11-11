#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using PII=pair<int,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int M=5e5+5,N=505;
vector<PII> e[M];
int c,n,m,d,q;
ll w[M],g[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k; scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x; ll t; scanf("%d%lld",&x,&t);
			e[x].push_back({i,t});
		}
	}
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			int u=e[i][j].first;
			for(int k=j+1;k<e[i].size();k++){
				int v=e[i][k].first;
				ll val=e[i][j].second+e[i][k].second;
				g[u][v]=g[v][u]=min(g[u][v],val);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		}
	}
	while(q--){
		int x,y; scanf("%d%d",&x,&y);
		ll ans=inf;
		for(int j=0;j<e[x].size();j++){
			int u=e[x][j].first;
			for(int k=0;k<e[y].size();k++){
				int v=e[y][k].first;
				ll val=e[x][j].second+e[y][k].second;
				ans=min(ans,val+g[u][v]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

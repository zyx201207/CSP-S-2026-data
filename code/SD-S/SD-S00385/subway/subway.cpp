#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=5e5+5;
const ll inf=3e18;
ll f[505][505];
int id,n,m,d,q;
int w[N];
int h[N];
vector<pii> g[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&id,&n,&m,&d,&q);
	for(int i=1;i<=m;++i) scanf("%d",&w[i]);
	for(int i=1;i<=n;++i){
		int k; scanf("%d",&k);
		while(k--){
			int x,t;
			scanf("%d%d",&x,&t);
			g[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) f[i][j]=inf;
	for(int i=1;i<=n;++i) f[i][i]=0;
	for(int u=1;u<=m;++u){
		int len=g[u].size();
		for(int i=0;i<len;++i) for(int j=i+1;j<len;++j){
			int  x=g[u][i].first, y=g[u][j].first;
			int tx=g[u][i].second,ty=g[u][j].second;
			f[x][y]=f[y][x]=min(f[x][y],(ll)(tx+ty));
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y; scanf("%d%d",&x,&y);
		ll ans=inf;
		for(pii i:g[x]) for(pii j:g[y]){
			int u=i.first,v=j.first;
			ans=min(ans,f[u][v]+w[x]+w[y]+i.second+j.second);
		}
		printf("%lld\n",ans);
	}
	return 0;
}


#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500+10;
const int maxm=500000+10;
const ll inf=1e16;
int tid,n,m,d,q,w[maxm];
ll f[maxn][maxn];
struct node{
	int u,w;
};
vector<node> e[maxm];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int x,y,t,ct;
	cin>>tid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&ct);
		for(int j=1;j<=ct;j++) scanf("%d%d",&x,&t),e[x].push_back({i,t});
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) f[i][j]=inf;
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)e[i].size();j++){
			int u=e[i][j].u;
			int w1=e[i][j].w;
			for(int k=j+1;k<(int)e[i].size();k++){
				int v=e[i][k].u;
				int w2=e[i][k].w;
				ll dis=min(f[u][v],(ll)w1+w2);
				f[u][v]=f[v][u]=dis;
			}
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		scanf("%d%d",&x,&y);
		ll ans=inf;
		for(int i=0;i<(int)e[x].size();i++){
			int u=e[x][i].u;
			int w1=e[x][i].w;
			for(int j=0;j<(int)e[y].size();j++){
				int v=e[y][j].u;
				int w2=e[y][j].w;
				ll dis=(ll)w[x]+w[y]+w1+w2+f[u][v];
				ans=min(ans,dis);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500510,M=510;
int c,n,m,z,q;
int k[N],vis[N];
ll w[N],d[N];
ll sta[M][M];
struct Edge{
	int v;
	ll w;
};
vector <Edge> g[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&z,&q);
	for (int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for (int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		int ai,u=i+m;
		ll ci;
		for (int j=1;j<=k[i];j++){
			scanf("%d%lld",&ai,&ci);
			g[ai].push_back({u,ci});
			g[u].push_back({ai,ci});
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			sta[i][j]=1e18;
		}
	}
	for (int i=1;i<=n;i++) sta[i][i]=0;
	for (int i=1;i<=m;i++){
		for (int j=0;j<g[i].size();j++){
			int u1=g[i][j].v-m;
			for (int l=j+1;l<g[i].size();l++){
				int u2=g[i][l].v-m;
				sta[u1][u2]=sta[u2][u1]=min(sta[u1][u2],g[i][j].w+g[i][l].w);
			}
		}
	}
	for (int l=1;l<=n;l++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				sta[i][j]=min(sta[i][j],sta[i][l]+sta[l][j]);
	while (q--){
		int s,t;
		scanf("%d%d",&s,&t);
		ll ans=1e18,ww=w[s]+w[t];
		for (int i=0;i<g[s].size();i++){
			int u1=g[s][i].v-m;
			for (int j=0;j<g[t].size();j++){
				int u2=g[t][j].v-m;
				ans=min(ans,ww+g[s][i].w+sta[u1][u2]+g[t][j].w);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//100pts
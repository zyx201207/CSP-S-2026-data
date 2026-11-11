#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e2+5;
const int M=5e5+5;
int C;
int n,m,d,q;
int k[N],w[M];
vector<pair<int,ll> >sub[M];
ll dis[N][N];

/*
vector<int >G[N];
int dep[N],siz[N],mxs[N],f[N],top[N],dfn[N],pre[N];
int tot;
void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;
	siz[u]=1;f[u]=fa;
	for(int v:G[u]){
		if(v==fa) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[mxs[u]]) mxs[u]=v;
	}
}
void dfs2(int u,int fa,int t){
	top[u]=t;dfn[u]=++tot;pre[tot]=u;
	for(int v:G[u]){
		if(v==fa) continue;
		dfs2(v,u,v);
	}
}
int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=f[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	return u;
}
I love 树剖.
*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;cin>>x>>y;
			sub[x].push_back({i,y});
		}
	}
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<sub[i].size();j++){
			for(int l=j+1;l<sub[i].size();l++){
				int u=sub[i][j].first,v=sub[i][l].first;
				ll ul=sub[i][j].second,ur=sub[i][l].second;
				dis[u][v]=min(dis[u][v],ul+ur);
				dis[v][u]=min(dis[v][u],dis[u][v]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int l=1;l<=n;l++){
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		ll ans=1e18;
		for(int l=0;l<sub[x].size();l++){
			for(int r=0;r<sub[y].size();r++){
				int u=sub[x][l].first,v=sub[y][r].first;
				ll ul=sub[x][l].second,ur=sub[y][r].second;
				ans=min(ans,dis[u][v]+ul+ur);
				//cout<<u<<' '<<v<<' '<<ans<<'\n';
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
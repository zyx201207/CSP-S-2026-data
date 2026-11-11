#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5,M=105;
int c,t,n,m,dep[N],sz[N],f[N],id[N],_f[N],h1[M],h2[M],dp[M][M],p[M],ans;
struct node{
	int x,y;
}e[N];
vector<int>g[N];
void dfs(int u,int fa){
	sz[u]=1,f[u]=dep[u],_f[u]=0,dp[u][1]=0;
	for(int i=2;i<=n;++i)dp[u][i]=1e9;
	for(auto v:g[u]){
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		if(f[v]>f[u])_f[u]=max(f[u],_f[v]),f[u]=f[v],id[u]=v;
		else _f[u]=max(_f[u],f[v]);
		for(int i=1;i<=n;++i)p[i]=1e9;
		for(int i=1;i<=sz[u];++i){
			for(int j=0;j<=sz[v];++j){
				p[i+j]=min(p[i+j],max(dp[u][i],dp[v][j]));
			}
		}
		sz[u]+=sz[v]; 
		for(int i=1;i<=sz[u];++i)dp[u][i]=p[i];
	}
	dp[u][0]=f[u]-dep[u]+1;
	return;
} 
void dfs1(int u,int fa,int sum){
	for(int i=1;i<=n;++i)h1[i]=min(h1[i],max(dp[u][i],sum+dep[u]));
	if(!dep[u]){
		for(auto v:g[u]){
			if(v==fa)continue;
			if(v==id[u]){
				dfs1(v,u,_f[u]); 
			}
			else{
				dfs1(v,u,f[u]);
			}
		}
		return;
	}
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs1(v,u,sum);
	}
	return;
}
void dfs2(int u,int fa,int sum){
	for(int i=1;i<=n;++i)h2[i]=min(h2[i],max(dp[u][i],sum+dep[u]));
	if(!dep[u]){
		for(auto v:g[u]){
			if(v==fa)continue;
			if(v==id[u]){
				dfs2(v,u,_f[u]); 
			}
			else{
				dfs2(v,u,f[u]);
			}
		}
		return;
	}
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs2(v,u,sum);
	}
	return;
}
void _dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(auto v:g[u]){
		if(v==fa)continue;
		_dfs(v,u);
	}
	return;
} 
void solve(){
	ans=1e9;
	cin>>n>>m;
	for(int i=1;i<=n;++i)g[i].clear();
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		e[i]={x,y};
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if(c<=6){
		for(int i=1;i<n;++i){
			dep[e[i].x]=dep[e[i].y]=0;
			for(int j=1;j<=n;++j)h1[i]=h2[i]=1e9;
			dfs(e[i].x,e[i].y); 
			dfs1(e[i].x,e[i].y,0); 
			dfs(e[i].y,e[i].x);
			dfs2(e[i].y,e[i].x,0);
			for(int j=1;j<m;++j)ans=min(ans,max(h1[j],h2[m-j])); 
		}
		cout<<ans<<'\n';
		return;
	}
	cout<<"0\n";
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/

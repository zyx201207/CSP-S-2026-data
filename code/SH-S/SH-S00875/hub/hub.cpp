#include<bits/stdc++.h>
using namespace std;
vector<int>g[1010100];
int dep[1010100],f[1010100][22];
int c,tt;
int n,k;
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i = 1;i<=20;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int i = 0;i<g[x].size();i++){
		int y=g[x][i];
		if(y==fa)continue;
		dfs(y,x);
	} 
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i = 20;i>=0;i--)
		if(dep[f[u][i]]>=dep[v])u=f[u][i];
	if(u==v)return u;
	for(int i = 20;i>=0;i--)
		if(f[u][i]!=f[v][i])
			u=f[u][i],v=f[v][i];
	return f[u][0];
}
int dist(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}


bool hav[15][15];
int b[15];
int rt(int x){return x==b[x]?x:b[x]=rt(b[x]);}
void un(int x,int y){b[rt(x)]=rt(y);} 
void fun2(){
	int ret=1e9;
	for(int i = 1;i<=n;i++)
		for(int j = 0;j<g[i].size();j++)
			hav[i][g[i][j]]=1; 
	
	for(int msk = 1;msk<(1<<n);msk++){
		if(__builtin_popcount(msk)!=k)continue;
		for(int i = 1;i<=n;i++)b[i]=i;
		
		for(int i = 1;i<n;i++)
			for(int j = i+1;j<=n;j++)
				if(msk&(1<<i-1) and msk&(1<<j-1) and hav[i][j])
					un(i,j);
		int cnt=0;
		for(int i = 1;i<=n;i++)
			if(msk&(1<<i-1))
				cnt+=(rt(i)==i);
		if(cnt>2)continue;
		int ans=0;
		for(int i = 1;i<=n;i++){
			int mx=1e9;
			for(int j = 1;j<=n;j++){
				if(msk&(1<<j-1))
					mx=min(mx,dist(i,j));
			}
			ans=max(ans,mx);
		}
		ret=min(ret,ans);
	}
	cout<<ret<<"\n";
}
void fun(){
	cin>>n>>k;
	for(int i = 1;i<=n;i++)g[i].clear();
	memset(hav,0,sizeof(hav));
	for(int i = 1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	} 
	dfs(1,0);
	fun2();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>tt;
	while(tt--)fun();
	return 0;
}

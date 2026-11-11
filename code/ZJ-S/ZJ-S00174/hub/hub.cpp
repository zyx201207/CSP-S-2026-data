#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k,vis[N],ans,fa[N],dep[N];
vector<int> g[N];
int st[N][20];
void dfs(int u,int fff){
	st[u][0]=fff;
	dep[u]=dep[fff]+1;
	for(int i=1;i<=18;i++)
		st[u][i]=st[st[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v!=fff){
			dfs(v,u);
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=18;i>=0;i--){
		if(dep[x]-(1<<i)>=dep[y]) x=st[x][i];
	}
	if(x==y) return x;
	for(int i=18;i>=0;i--){
		if(st[x][i]!=st[y][i]){
			x=st[x][i];
			y=st[y][i];
		}
	}
	return st[x][0];
}
int jj(int x,int y){
	int l=lca(x,y);
	return dep[x]+dep[y]-2*dep[l];
}
int find(int k){
	if(k==fa[k]) return k;
	return fa[k]=find(fa[k]);
}
int js(){
	int s=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			for(auto v:g[i]){
				if(vis[v]==1){
					fa[find(v)]=find(i);
				}
			}
		}
	}
	int ff1=-1,ff2=-1;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			if(ff1==-1) ff1=find(i);
			else{
				if(ff1!=find(i)){
					if(ff2==-1) ff2=find(i);
					else{
						if(ff2!=find(i)) return -1;
					}
				}
			}
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		int mn=INT_MAX;
		for(int j=1;j<=n;j++){
			if(vis[j]==1){
				mn=min(mn,jj(i,j));
			}
		}
		mx=max(mx,mn);
	}
	return mx;
}
void dfs1(int u,int s){
	if(u==n+1){
		if(s<k) return;
		int ss=js();
		if(ss!=-1) ans=min(ans,ss);
		return;
	}
	dfs1(u+1,s);
	if(s<k){
		vis[u]=1;
		dfs1(u+1,s+1);
	}
	vis[u]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=INT_MAX;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dep[0]=-1;
		dfs(1,0);
		dfs1(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
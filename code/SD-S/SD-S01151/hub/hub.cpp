#include<bits/stdc++.h>
using namespace std;
int n,k,dep[55];
bool vis[50];
vector<int> g[55];
void dfs(int x){
	vis[x]=0;
	for(int v:g[x]){
		if(!vis[v]) continue;
		dfs(v);
	}
}
void dfs1(int x,int fa){
	for(int v:g[x]){
		if(v==fa) continue;
		dep[v]=dep[x]+1; dfs1(v,x);
	}
}
bool check(int s){
	for(int i=0;i<n;i++){
		if(s>>i&1) vis[i+1]=1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			dfs(i); cnt++;
		}
	}
	if(cnt>2) return 0;
	return 1;
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	int ans=n+1;
	for(int i=1;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k) continue;
		if(!check(i)) continue;
		int maxn=0;
		for(int j=1;j<=n;j++){
			dep[j]=0; dfs1(j,0); int minn=n+1;
			for(int k=1;k<=n;k++){
				if(i>>(k-1)&1) minn=min(minn,dep[k]);
			}
			maxn=max(maxn,minn);
		}
		ans=min(ans,maxn);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	int c,t; scanf("%d%d",&c,&t);
	while(t--) solve(); 
	return 0;
} 

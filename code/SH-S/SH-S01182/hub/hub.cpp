#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,k,ans,dep[N],fa[N][21],s[N];
vector<int> g[N];
void dfs1(int u,int f){
	dep[u]=dep[f]+1;fa[u][0]=f;
	for(int i=1;i<=20;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:g[u]){
		if(v==f) continue;
		dfs1(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];y=fa[y][i];
		}
	} 
	return fa[x][0];
}
int dis(int x,int y){
	int l=lca(x,y);
	return dep[x]+dep[y]-2*dep[l];
}
void dfs2(int u,int cnt){
	if(u==n+1){
		if(cnt<=k) return;
		int sum=0;
		for(int j=1;j<=k;j++) cout<<s[j]<<' ';
		cout<<'\n'; 
		for(int i=1;i<=n;i++){
			int kkksc=1e18;
			for(int j=1;j<=k;j++){
				kkksc=min(kkksc,dis(i,s[j]));
			}
			cout<<kkksc<<' ';
			sum=max(sum,kkksc);
		}
		cout<<'\n'<<sum<<' '<<ans<<'\n';
		ans=min(ans,sum);
		return;
	}
	dfs2(u+1,cnt);
	if(cnt<=k){
		s[cnt]=u;
		dfs2(u+1,cnt+1);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int tid,_;
	cin>>tid>>_;
	while(_--){
		cin>>n>>k;int u,v;ans=1e18;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs1(1,0);
		dfs2(1,1);
		cout<<ans<<'\n';
	}
	return 0;
}

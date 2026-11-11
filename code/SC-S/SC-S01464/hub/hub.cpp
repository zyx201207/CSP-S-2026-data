#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,u,v,fa[1000010][20],dep[1000010];
vector<int>adj[1000010];
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for(int i=1;i<=19;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:adj[u]){
		if(v==f) continue;
		dfs(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int dif=dep[u]-dep[v];
	for(int i=0;i<=19;i++){
		if((dif>>i)&1) u=fa[u][i];
	}
	if(u==v) return u;
	for(int i=19;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}
int len(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		/*
		n         C C C C
		n/2       | | | |
		n/2+1     C-C-C-C
		*/
		if(n==k){
			cout<<0<<'\n';
		}
		else if(k>=n/2){
			cout<<1<<'\n';
		}
		else{
			n=n/2;
			cout<<(n-k)/4+2*(n%3)<<'\n'; // 这能对吗？？？？
		}
	}
	return !"I'm xcb";
}
/*
预测：
100+100+32+[0,10]=[232,242]

*/
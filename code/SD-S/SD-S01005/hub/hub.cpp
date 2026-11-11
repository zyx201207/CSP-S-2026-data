#include<bits/stdc++.h>
using namespace std;
int ccc,t,n,k,dep[1000009],f[1000009][33],b[1000009],c[1000009],vis[1000009],mn;
vector<int> v[1000009];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]!=fa){
			dfs(v[u][i],u);
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=30;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=30;i>=0;i--){
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void dfs11(int u){
	vis[u]=1;
	for(int i=0;i<v[u].size();i++){
		if((!c[v[u][i]])||vis[v[u][i]]) continue;
		dfs11(v[u][i]);
	}
}
void dfsdfs(int t){
	if(t>k){
		for(int i=1;i<=n;i++) vis[i]=0;
		int res=0;
		for(int i=1;i<=k;i++){
			if(!vis[b[i]]){
				dfs11(b[i]);
				res++;
			}
		}
		if(res>2) return ;
		//for(int i=1;i<=k;i++) cout<<b[i]<<' ';
		//cout<<'\n';
		int mx=0;
		for(int i=1;i<=n;i++){
			int mnn=2e9;
			for(int j=1;j<=k;j++){
				mnn=min(mnn,dis(i,b[j]));
			}
			mx=max(mx,mnn);
		}
		mn=min(mn,mx);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==1) continue;
		b[t]=i;
		c[i]++;
		dfsdfs(t+1);
		c[i]--;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>ccc>>t;
	while(t--){
		cin>>n>>k;
		mn=2e9;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		for(int j=1;j<=30;j++) for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
		dfsdfs(1);
		cout<<mn<<'\n';
	}
	
	
	
	return 0;
}
/*
³æÐè
ÔÆÁ¦
°×É×
³æÇÒ 
*/

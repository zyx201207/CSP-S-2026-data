#include<bits/stdc++.h>
using namespace std;
int c,T;
vector<int> v[100010];
int n,k;
int ans,vis[100010],dep[100010],dp[1010][1010],fa[100010],maxdep[100010];
queue<int> q;
priority_queue<pair<int,int> > Q;
void dfs(int u,int f){
	fa[u]=f;
	dep[u]=dep[f]+1;
	maxdep[u]=dep[u];
	for(auto i:v[u]){
		if(i==f) continue;
		dfs(i,u);
		maxdep[u]=max(maxdep[u],maxdep[i]);
	}
	int now=1;
	while(!Q.empty()) Q.pop();
	for(auto i:v[u])
		if(i!=f) Q.push({maxdep[i]-dep[u],i});
	while(!Q.empty()){
		if(now>k) break;
		dp[u][now]=Q.top().first;
		int x=Q.top().second;
		Q.pop();
		for(auto i:v[x])
			if(i!=fa[x]) Q.push({maxdep[i]-dep[x],i});
		now++;
	}
}
int lca(int x,int y){
	while(x!=y){
		if(dep[x]<dep[y]) y=fa[y];
		else x=fa[x];
	}
	return x;
}
int LCA[1010][1010];
int check(int u,int v){
	return LCA[u][v]!=u;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	if(c<=6){
		while(T--){
			cin>>n>>k;
			for(int i=1;i<=n;i++) v[i].clear();
			for(int i=1;i<n;i++){
				int x,y;
				cin>>x>>y;
				v[x].emplace_back(y),v[y].emplace_back(x);
			}
			int ans=2e9;
			for(int rt=1;rt<=n;rt++){
				for(int i=1;i<=n;i++)
					for(int j=1;j<=k;j++) dp[i][j]=2e9;
				dfs(rt,0);
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++) LCA[i][j]=lca(i,j);
				for(int i=1;i<=n;i++){
					int now=dp[i][k];
					for(int j=1;j<=n;j++)
						if(check(i,j)) now=max(now,dep[i]+dep[j]-2*dep[LCA[i][j]]);
					ans=min(ans,now);
					for(int j=1;j<=n;j++){
						now=2e9;
						if(!check(i,j)||!check(j,i)) continue;
						for(int p=1;p<k;p++) now=min(now,max(dp[i][p],dp[j][k-p]));
						for(int p=1;p<=n;p++) if(check(i,p)&&check(j,p)) now=max(now,min(dep[i]+dep[p]-2*dep[LCA[i][p]],dep[j]+dep[p]-2*dep[LCA[j][p]]));
						ans=min(ans,now);
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
}
//RP++

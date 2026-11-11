#include<bits/stdc++.h>
using namespace std;
vector<int> g[2000010];
bool used[2000010],vis[2000010];
int fa[22][2000010],deep[2000010];
void dfs(int u){
	for(auto v:g[u]){
		if(vis[v]==1) continue;
		if(used[v]!=used[u]) continue;
		vis[v]=1;
		dfs(v);
	}
	return ;
}
void dfs1(int u,int faa){
	fa[0][u]=faa;
	deep[u]=deep[faa]+1;
	for(auto v:g[u]){
		if(v!=faa){
			dfs1(v,u);
		}
	}
	return ;
}
int lca(int u,int v){
	if(deep[u]>deep[v]){
		swap(u,v);
	}
	int cd=deep[v]-deep[u];
	for(int i=21;i>=0;i--){
		if(cd&(1<<i)){
			v=fa[i][v];
		}
	}
	if(u==v) return u;
	for(int i=21;i>=0;i--){
		if(fa[i][u]!=fa[i][v]){
			u=fa[i][u];
			v=fa[i][v];
		}
	}
	return fa[0][u];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int full=(1<<n)-1,ans=1e9;
		for(int mask=1;mask<=full;mask++){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(mask&(1<<(i-1))) cnt++;
			}
			if(cnt!=k) continue;
			memset(vis,0,sizeof vis);
			memset(used,0,sizeof used);
			vector<int> temp;
			for(int i=1;i<=n;i++){
				if(mask&(1<<(i-1))) {
					used[i]=1;
					temp.push_back(i);
				}
			}
			cnt=0;
			for(int i=1;i<=n;i++){
				if(vis[i]==0){
					vis[i]=1;
					dfs(i);
					if(used[i]==1) cnt++;
				}
			}
			if(cnt>2) continue;
			dfs1(1,1);
			for(int i=1;i<=21;i++){
				for(int j=1;j<=n;j++){
					fa[i][j]=fa[i-1][fa[i-1][j]];
				}
			}
			int maxv=0;
			for(int i=1;i<=n;i++){
				if(used[i]==1) continue;
				int minv=1e9;
				for(auto v:temp){
					minv=min(minv,deep[i]+deep[v]-deep[lca(i,v)]-deep[fa[0][lca(i,v)]]);
				}
				maxv=max(maxv,minv);
			}
//			if(maxv==2) cout<<mask<<" ";
			ans=min(ans,maxv);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
#include<bits/stdc++.h>
#define int long long
#define I using
#define AK namespace
#define CSP std
I AK CSP;
int c,Big_J,n,m,ans,minn;
bool vis[1000005],vis2[1000005];
vector<int> e[1000005];
void dfs2(int u,int fa){
	if(!vis[u]) return;
	vis2[u]=1;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs2(v,u);
	}
	return;
}
void dfs3(int u,int fa,int di){
	if(vis[u]) minn=min(minn,di);
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs3(v,u,di+1);
	}
	return;
}
void dfs(int k,int cnt2){
	if(cnt2>m) return;
	if(k>n){
		if(cnt2!=m) return;
		for(int i=1;i<=n;i++) vis2[i]=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]&&!vis2[i]){
				dfs2(i,-1);
				cnt++;
			}
		}
		if(cnt>2) return;
		int maxn=0;
		for(int i=1;i<=n;i++){
			minn=1e18;
			dfs3(i,-1,0);
			maxn=max(maxn,minn);
		}
		ans=min(maxn,ans);
		return;
	}
	vis[k]=1;
	dfs(k+1,cnt2+1);
	vis[k]=0;
	dfs(k+1,cnt2);
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>Big_J;
	while(Big_J--){
		cin>>n>>m;
		ans=1e18;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}

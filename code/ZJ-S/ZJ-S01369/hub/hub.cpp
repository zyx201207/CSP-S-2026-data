#include<bits/stdc++.h>
using namespace std;
int c,t,f[1001][1001],vis[1001],u[1001],v[1001],ans,n,k;
vector<int> mp[1001];
void dfs(int x,int fa,int rt){
	for(auto &i:mp[x]){
		if(i!=fa){
			f[rt][i]=f[rt][x]+1;
			f[i][rt]=f[rt][x]+1;
			dfs(i,x,rt);
		}
	}
}
void dfs2(int x,int cnt){
	if(x>n||cnt==k){
		if(cnt<k) return ;
		int fw=0;
		for(int i=1;i<n;i++){
			if(vis[u[i]]&&vis[v[i]]) fw++;
		} 
		if(fw>=k-2){
			int mi=0;
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					int w=1e9;
					for(int j=1;j<=n;j++){
						if(vis[j]) w=min(w,f[i][j]);
					}
					mi=max(mi,w);
				}
			}
			ans=min(ans,mi);
		}
		return ;
	}
	dfs2(x+1,cnt);
	vis[x]=1;
	dfs2(x+1,cnt+1);
	vis[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=1e9;
		for(int i=1;i<=n;i++) mp[i].clear();
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
			mp[u[i]].push_back(v[i]);
			mp[v[i]].push_back(u[i]);
		}
		for(int i=1;i<=n;i++){
			dfs(i,0,i);
		}
		dfs2(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
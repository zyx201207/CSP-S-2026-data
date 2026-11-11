#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> vt[15];
bool vis[15];
bool bj[15];
void dfs2(int u,int fa){
	bj[u]=1;
	for(int i=0;i<vt[u].size();i++){
		int to=vt[u][i];
		if(to==fa||(!vis[to])) continue;
		dfs2(to,u);
	}
}
int dis=1e9;
void dfs3(int u,int fa,int d){
	if(vis[u]){
		dis=min(dis,d);
		return ;
	}
	for(int i=0;i<vt[u].size();i++){
		int to=vt[u][i];
		if(to==fa) continue;
		dfs3(to,u,d+1);
	}
}
int ans;
void dfs(int d,int ge){
	if(d==n+1){
		if(ge!=k) return ;
		int cnt=0;
		memset(bj,0,sizeof(bj)); 
		for(int i=1;i<=n;i++){
			if(vis[i]&&(!bj[i])){
				dfs2(i,0);
				cnt++;
			}
		}
		if(cnt<=2){
			int aans=0;
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					dis=1e9;
					dfs3(i,0,0);
					aans=max(aans,dis);
				}
			}
			ans=min(ans,aans);
		}
		return ;
	}
	vis[d]=1;
	dfs(d+1,ge+1);
	vis[d]=0;
	dfs(d+1,ge);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) vt[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		ans=1e9;
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}


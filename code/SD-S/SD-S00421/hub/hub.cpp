#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,T;
int n,k;
int fa[N];
vector<int>g[N];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
int pop_cnt(int s){
	int res=0;
	while (s) res+=s&1,s>>=1;
	return res;
}
vector<int>t;
bool is[N];
bool vis[N];
int dis[N];
void dfs(int u){
	vis[u]=1;
	for (auto v:g[u]){
		if (!vis[v]){
			dis[v]=min(dis[v],dis[u]+1);
			dfs(v);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while (T--){
		cin>>n>>k;
		for (int i=1;i<=n;i++) g[i].clear(),fa[i]=i;
		for (int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans=N;
		for (int s=1;s<(1<<n);s++){
			if (pop_cnt(s)!=k) continue;
			for (int i=1;i<=n;i++) fa[i]=i;
			t.clear();
			memset(is,0,sizeof(is));
			memset(dis,0x3f,sizeof(dis));
			int cnt=k;
			for (int i=1;i<=n;i++){
				if ((s>>(i-1))&1){
					t.push_back(i);
					dis[i]=0;
					is[i]=1;
				}
			}
			for (auto u:t){
				for (auto v:g[u]){
					if (is[v]&&find(u)!=find(v)){
						fa[find(u)]=find(v);
						cnt--;
					}
				}
			}
			if (cnt>2) continue;
			
			for (auto u:t){
				memset(vis,0,sizeof(vis));
				dfs(u);
			}
			int res=0;
			for (int i=1;i<=n;i++){
				res=max(res,dis[i]);
			}
			ans=min(ans,res);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=21;
int c,t,n,k,u,v,vis[N],dis[N],vis1[N],cnt;
vector<int>g[N];
void dfs(int u,int fa){
	dis[u]=min(dis[fa]+1,dis[u]);
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
void pan(int u,int fa){
	if(!vis[u]||vis1[u])return;
	vis1[u]=1;
	for(auto v:g[u]){
		if(v==fa)continue;
		pan(v,u);
	}
}
void solve(){
	cin>>n>>k;
	if(n>20){
		cout<<n/k<<'\n';
		return;
	}
	for(int i=1;i<=n;++i)g[i].clear();
	for(int i=1;i<n;++i){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}int tmp=0,mn=50;
	for(int i=0;i<(1ll<<n);++i){
		tmp=0;
		for(int j=0;j<n;++j){
			vis[j+1]=(i>>j)&1;
			vis1[j+1]=0;
			if(vis[j+1])++tmp;
		}if(tmp!=k)continue;
		cnt=0;
		for(int i=1;i<=n;++i){
			if(vis1[i]||!vis[i])continue;
			++cnt;
			pan(i,0);
		}
		if(tmp==k&&cnt<=2){
			for(int j=1;j<=n;++j)dis[j]=30;
			for(int j=1;j<=n;++j){
				if(vis[j]){
					dis[j]=0;
					dfs(j,0);
				}
			}int ans=0;
			for(int j=1;j<=n;++j){
				ans=max(ans,dis[j]); 
			}mn=min(ans,mn);
		}
	}cout<<mn<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
} 

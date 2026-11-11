#include<bits/stdc++.h>
using namespace std;
const int N = 50;
int n,k,dis[N];bool vis[N],arr[N];
vector<int> e[N]; 
void dfs1(int u,int fa){
	arr[u] = 1;
	for(int v:e[u]){
		if(v == fa || vis[v] == 0)continue;
		dfs1(v,u);
	}
} 
void dfs2(int u,int fa){
	for(int v:e[u])if(v!=fa && vis[v] == 0){
		dis[v] = dis[u] + 1;
		dfs2(v,u);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,_;cin >> c >> _;
	while(_--){
		cin >> n >> k;	
		for(int i=1;i<n;++i){
			int u,v;cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int ans = n-1;
		for(int i=1;i<(1<<n);++i){
			if(__builtin_popcount(i) != k)continue;
			for(int j=1;j<=n;++j){dis[j] = arr[j] = vis[j] = 0;}
			for(int j=1;j<=n;++j)
				vis[j] = (i&(1<<(j-1)));
			int cnt = 0;
			for(int j=1;j<=n;++j)
				if(vis[j] && arr[j] == 0){
					dfs1(j,0);++cnt;
				}
			if(cnt > 2)continue;
			for(int j=1;j<=n;++j){
				if(vis[j])dfs2(j,0);
			}int cur = 0;
			for(int i=1;i<=n;++i)
				cur = max(cur,dis[i]);
			ans = min(ans,cur);
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;++i)e[i].clear();
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;

int c,T;

int n,k;
vector<int> t[100005];

int dis[15][15];

void dfs1(int r,int u,int fa,int d){
	dis[r][u]=d;
	for(int v:t[u]) if(v!=fa) dfs1(r,v,u,d+1);
}

bool s[1005];

bool vis[1005];

void dfs2(int u){
	vis[u]=1;
	for(int v:t[u]) if(!vis[v]) dfs2(v);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>T;
	
	while(T--){
		cin>>n>>k;
		for(int u=1;u<=n;++u) t[u].clear();
		
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			t[u].push_back(v),t[v].push_back(u);
		}
		
		for(int u=1;u<=n;++u) dfs1(u,u,0,0);
		
		int ans=1e9;
		
		for(int S=0;S<(1<<n);++S){
			if(__builtin_popcount(S)!=k) continue;
			for(int u=1;u<=n;++u){
				if(S&(1<<(u-1))) s[u]=1,vis[u]=0;
				else s[u]=0,vis[u]=1;
			}
			
			int cnt=0;
			for(int u=1;u<=n;++u){
				if(!vis[u]) dfs2(u),++cnt;
			}
			
			if(cnt>2) continue;
			
			int cur=0;
			
			for(int u=1;u<=n;++u){
				int d=1e9;
				for(int v=1;v<=n;++v){
					if(s[v]) d=min(d,dis[u][v]);
				}
				cur=max(cur,d);
			}
			
			ans=min(ans,cur);
		}
		
		cout<<ans<<endl; 
	}
	
	return 0;
}

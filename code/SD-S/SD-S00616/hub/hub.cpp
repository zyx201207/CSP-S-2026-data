#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e6+7;
int n,k;
vector<int>g[N];
bool use[N];
bool vis[N];
int dis[N];
int ans;

void dfs(int x){
	vis[x]=1;
	for(auto u:g[x]){
		if(use[u]&&!vis[u]){
			dfs(u);
		}
	}
}

bool check(){
	for(int i=1;i<=n;i++)vis[i]=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(use[i]&&!vis[i]){
			dfs(i);
			cnt++;
		}
	}
	return cnt>2;
}

void DFS(int pos,int las){
	if(pos>k){
		if(check())return;
		queue<int>q;
		for(int i=1;i<=n;i++)dis[i]=1e18;
		for(int i=1;i<=n;i++)if(use[i]){
			dis[i]=0;
			q.push(i);
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:g[u]){
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
		}	
		int maxn=0;
		for(int i=1;i<=n;i++)maxn=max(maxn,dis[i]);
		ans=min(maxn,ans);
		return;
	}
	for(int i=las+1;i<=n;i++){
		if(use[i])continue;
		use[i]=1;
		DFS(pos+1,i);
		use[i]=0;
	}
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=1e18;
		for(int i=1;i<=n;i++)g[i].clear();
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		DFS(1,0);
		cout<<ans<<'\n';
	}
}


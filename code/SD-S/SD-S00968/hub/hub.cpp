#include <bits/stdc++.h>
using namespace std;

int n,k,dist[4005];
bool vis[4005],used[4005];
vector<vector<int>> g;
vector<int> tmp;

void dfs1(int u){
	for(const auto &i:g[u]){
		if(vis[i] || !used[i]) continue;
		vis[i]=true;
		dfs1(i);
	}
}

bool check(){
	memset(vis,0,sizeof(vis));
	int cnt=0;
	for(const auto &i:tmp){
		if(vis[i]) continue;
		dfs1(i);
		cnt++;
	}
	return cnt<=2;
}

void dfs2(int u,int fa,int step){
	if(step>dist[u]) return;
	if(step<=dist[u]) dist[u]=step;
	for(const auto &i:g[u]){
		if(i==fa) continue;
		dfs2(i,u,step+1);
	}
}

int d(int x){
	if(used[x]) return 0;
	fill(dist,dist+n+5,0x3f3f3f3f);
	dfs2(x,0,0);
	int res=INT_MAX;
	for(const auto &i:tmp) res=min(res,dist[i]);
	return res;
}

void solve(){
	g.clear();
	cin>>n>>k;
	g.resize(n+1);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans=INT_MAX;
	for(int mask=0;mask<(1<<n);mask++){
		if(__builtin_popcount(mask)!=k) continue;
		memset(used,0,sizeof(used));
		tmp.clear();
		for(int i=0;i<n;i++) if(mask&(1<<i)) used[i+1]=true,tmp.push_back(i+1);
		if(!check()) continue;
		int now=INT_MIN;
		for(int i=1;i<=n;i++) now=max(now,d(i));
		ans=min(ans,now);
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c,T;
	cin>>c>>T;
	while(T--) solve(); 
	return 0;
}

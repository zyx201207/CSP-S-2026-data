#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10,mod=998244353;

int n,k;
vector<int> G[N];

int fa[N];

int dis[N];
bool pos[N];

bool vis[N];
int ans=1e18;

int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}

bool check(){
	
	for(int i=1;i<n;i++) fa[i]=i;
	
	int cnt=k;
	for(int i=1;i<n;i++){
		if(vis[i]){
			for(int v : G[i]){
				if(!vis[v]) continue;
				if(find(i)!=find(v)){
					fa[find(i)]=fa[find(v)];
					cnt--;
				}
			}
		}
	}
	
	if(cnt>2) return 0;
	else return 1;
	
}

struct edge{
	int u,dis;
};

bool operator >(edge x,edge y){
	return x.dis<y.dis;
}

int dij(int s){
	
	priority_queue<edge,vector<edge>,greater<edge>> q;
	
	for(int i=1;i<=n;i++){
		dis[i]=1e18;
		pos[i]=0;
	}
	q.push({s,0}); dis[s]=0;
	
	while(!q.empty()){
		auto tmp=q.top(); q.pop();
		int u=tmp.u;
		if(pos[u]) continue;
		pos[u]=1;
		for(int v : G[u]){
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				q.push({v,dis[v]});
			}
		}
	} 
	
	int mn=1e18;
	
	for(int i=1;i<=n;i++){
		if(vis[i] && s!=i) mn=min(mn,dis[i]);
	}
	
	return mn;
	
}

void dfs(int pos,int sum){
	if(pos>n && sum!=k) return;
	
	if(sum==k){
//		for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
//		cout<<"\n";
		if(check()){
//			for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
//			cout<<"\n";
			int mx=0;
			for(int i=1;i<=n;i++){
				if(vis[i]){
					mx=max(mx,dij(i));
				}
			}
			ans=min(ans,mx);
		}
		return;
	}
	
	vis[pos]=1;
	dfs(pos+1,sum+1);
	
	vis[pos]=0;
	dfs(pos+1,sum);
	
}

void init(){
	
	ans=1e18;
	for(int i=1;i<=n;i++){
		G[i].clear();
		vis[i]=0;
		fa[i]=i;
	}
	
}

void solve(){
	
	cin>>n>>k;
	
	init();
	
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1,0);
	
	cout<<ans<<"\n";
	
}

signed main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c,t; cin>>c>>t;
	
	while(t--) solve();
	
	return 0;
	
}

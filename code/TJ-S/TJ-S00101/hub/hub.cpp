#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,k,ans,dis[N],p[N],vis[N],vv[N],tans=1e18;
vector<int> e[N];
struct node{
	int id;
	long long val;
	bool operator<(const node &o)const{
		return val>o.val;
	}
};

void dijkstra(int s){
	priority_queue<node> q;
	fill(dis+1,dis+n+1,1e18);
	fill(vis+1,vis+n+1,0);
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		long long u=q.top().id,val=q.top().val;
		q.pop();
//		if(!vv[u])continue;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i];
			if(!vv[v])continue;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push({v,dis[v]});
			}
		}
	}
}

void dfs(int x){
	if(x==k+1){
		int ans=0;
		for(int i=1;i<=k;i++){
			dijkstra(p[i]);
			long long mn=1e18;
			for(int i=1;i<=k;i++)if(vv[i]){
				mn=min(mn,dis[i]);
			}
			ans=max(ans,mn);
		}
		tans=min(tans,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vv[i]){
			p[i]=i;
			vv[i]=1;
			dfs(x+1);
			vv[i]=0;
		}
	}
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v),e[v].push_back(u);
	}
	tans=1e18;
	dfs(1);
	cout<<tans<<'\n';
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int c,t;cin>>c>>t;
	for(;t--;)solve();
	return 0;
}


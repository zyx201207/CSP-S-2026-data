#include<bits/stdc++.h>
using namespace std;
#define int long long
#define P pair<int, int>
const int N = 2e6+5;
const int INF = 1e18;
int n, k,ans=INF;
vector<int> g[N];
int b[N];
int dist[N];
bool vis[N];
int color[N];
void dij(int start) {
	for(int i=1; i<=n; i++) {
		dist[i]=INF;
		vis[i]=0;
	}
	priority_queue<P,vector<P>,greater<P>> pq;
	pq.push({0,start});
	dist[start]=0;
	while(!pq.empty()) {
		P tmp = pq.top();
		pq.pop();
		int u = tmp.second;
		int dis = tmp.first;
		if(vis[u])
			continue;
		vis[u]=1;
		for(int v : g[u]) {
			if(b[u]==1) {
				dist[v]=0;
				pq.push({dist[v],v});
			} else if(dist[v]>dis+1) {
				dist[v]=dis+1;
				pq.push({dist[v],v});
			}
		}
	}
}
void check(int u,int fa) {
	color[u]=1;
	for(int v : g[u]) {
		if(b[v]==0)
			continue;
		if(v==fa)
			continue;
		check(v,u);
	}
}
void dfs(int kk,int sum) {
	if(sum>k) {
		return;
	}
	if(kk>n) {
		if(sum!=k)
			return;
		int res = 0,cnt = 0;
		for(int i=1; i<=n; i++) {
			if(b[i]==1) {
				if(color[i]==0) {
					check(i,0);
					cnt++;
				}
			}
		}
		if(cnt>2) {
			return;
		}
		for(int i=1; i<=n; i++) {
			dij(i);
			for(int j=1; j<=n; j++) {
//				cout<<dist[j]<<" ";
				res = max(dist[j],res);
			}
//			cout<<"\n";
		}
//		cout<<res<<"\n";
		ans = min(ans,res);
		return;
	}
	b[kk]=1;
	dfs(kk+1,sum+1);
	b[kk]=0;
	dfs(kk+1,sum);
}
signed main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0)->sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) {
		cin>>n>>k;
		for(int i=1; i<n; i++) {
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n==k) {
			cout<<"0\n";
		} else {
			dfs(1,0);
			cout<<ans<<"\n";
		}
		ans = INF;
		for(int i=1; i<n; i++) {
			g[i].clear();
		}
	}
	return 0;
}
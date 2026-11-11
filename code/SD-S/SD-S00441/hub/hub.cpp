/*
LUOGU UID 1208546
*/

#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e6+10;
const int INF=0x3f3f3f3f3f3f3f3f;
int c,T,n,k,f[N];
vector<int> g[N];
int dist[N],ans;
int vis[N];
queue<int> q;
int find(int x) {
	return (f[x]==x?x:f[x]=find(f[x]));
}
inline void bfs() {
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int v:g[u]) {
			if(dist[v]==-1) {
				dist[v]=dist[u]+1;
//				cerr<<"success"<<v<<endl;
				q.push(v);
			}
		}
	}
}
void dfs(int x) {
	if(x==n+1) {
		int cnt=0;
		for(int i=1;i<=n;i++) {
			f[i]=i;
			cnt+=vis[i];
		}
		for(int u=1;u<=n;u++) {
			if(!vis[u]) continue;
			for(int v:g[u]) {
				if(vis[v]) {
					if(find(u)!=find(v)) {
						f[find(u)]=find(v);
						cnt--;
					}
				}
			}
		}
		if(cnt>2) return;
		for(int i=1;i<=n;i++) {
			dist[i]=-1;
			if(vis[i]) {
				dist[i]=0;
				q.push(i);
			}
		}
		bfs();
		int res=-INF;
		for(int i=1;i<=n;i++) res=max(res,dist[i]);
		ans=min(ans,res);
//		if(res==1) {
//			for(int i=1;i<=n;i++) {
//				if(vis[i]) cout<<i<<" ";
//			}
//			cout<<endl;
//		}
		return;
	}
	if(k!=n-x+1) {
		vis[x]=0;
		dfs(x+1);
	}
	if(k) {
		vis[x]=1;
		k--;
		dfs(x+1);
		vis[x]=0;
		k++;
	}	
}
inline void solve() {
	cin>>n>>k;
	ans=INF;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(k==2) {
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				for(int k=1;k<=n;k++) {
					dist[k]=-1;
				}
				dist[i]=dist[j]=0;
				q.push(i);
				q.push(j);
				bfs();
				int res=-INF;
				for(int k=1;k<=n;k++) res=max(res,dist[k]);
				ans=min(ans,res);
			}
		}
		cout<<ans<<endl;
		return;
	}
	dfs(1);
	cout<<ans<<endl;
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}


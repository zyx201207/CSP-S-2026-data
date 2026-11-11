/*
LUOGU UID 1208546
*/

#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=2e6+10;
const int INF=0x3f3f3f3f3f3f3f3f;
int a[N];
int c,T,n,d;
vector<pair<int,int>> g[N];
int b[N];
int dist[N],f[N];
int vis[N];
deque<pair<int,int>> q;
inline void solve() {
	cin>>n>>d;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	int pt=1;
	for(int i=1;i<n;i++) {
		while(pt+1<=n&&a[pt+1]<=a[i]+d) pt++;
		b[i]=pt;
//		cerr<<i<<" "<<b[i]<<endl;
	}
	for(int i=1;i<=n;i++) g[i].clear();
	int ans=0;
	for(int st=n-1;st>=1;st--) {
		g[st].push_back({b[st],1});
		g[st+1].push_back({st,0});
		for(int i=st;i<=n;i++) dist[i]=INF,f[i]=0,vis[i]=0;
		dist[st]=0;
		f[st]=1;
		q.push_back({0,st});
		while(!q.empty()) {
			int u=q.front().second;
			q.pop_front();
			if(vis[u]) continue;
			vis[u]=1;
			if(f[u]>2) f[u]=-1;
			for(auto e:g[u]) {
				int v=e.first,w=e.second;
				if(dist[v]>dist[u]+w) {
					dist[v]=dist[u]+w,f[v]=f[u];
					if(w==0) q.push_front({dist[v],v});
					else q.push_back({dist[v],v});
				}
				else if(dist[v]==dist[u]+w) {
					if(f[u]==-1) f[v]=-1;
					else if(f[v]!=-1) f[v]+=f[u];
				}
			}
		}
		for(int ed=st+1;ed<=n;ed++) {
//			cerr<<st<<" "<<ed<<" "<<dist[ed]<<" "<<f[ed]<<endl;
			if(f[ed]==2) ans++;
		}
	}
	cout<<ans<<endl;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int c,t,n,k,dis[N][N];
bool vis[N],tr[N];
vector<int> g[N];
inline void dfs(int u,int fa,int s) {
	for(auto it:g[u]) {
		if(it!=fa) {
			dis[s][it]=dis[s][u]+1;
			dfs(it,u,s);
		}
	}
	return;
}
inline void dfs2(int u,int fa,int s) {
	for(auto it:g[u]) {
		if(it!=fa && tr[it]) {
			vis[it]=true;
			dfs(it,u,s);
		}
	}
	return;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(; t--;) {
		int ans=1e9;
		cin>>n>>k;
		for(int i=1,u,v; i<=n-1; i++) {
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1; i<=n; i++) {
			dfs(i,-1,i);
		}
		for(int ma=0; ma<(1<<n); ma++) {
			vector<int> v;
			for(int j=0; (1<<j)<n; j++) {
				if(ma&(1<<j)) {
					v.push_back(j);
				}
			}
			int cnt=0;
			for(auto it1:v) {
				int res=1e9;
				for(auto it2:v) {
					if(it1!=it2 && dis[it1][it2]!=0) {
						res=min(dis[it1][it2],res);
					}
				}
				cnt=max(res,cnt);
			}
			for(int i=1; i<=n; i++) {
				vis[i]=tr[i]=false;
			}
			int rc=0;
			for(auto it:v) {
				tr[it]=true;	
			}
			for(auto it:v) {
				if(!vis[it]) {
					vis[it]=true;
					dfs2(it,-1,0);
					rc++;
				}
			}
			if(v.size()==k && rc<=2) {

				ans=min(ans,cnt);
			}
			v.clear();
		}
		for(int i=1,u,v; i<=n; i++) {
			g[i].clear();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
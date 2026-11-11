#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=5e5+10;
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
unordered_map<int,int> t[N];
vector<int> a[N],e[M];
int c,n,m,d,Q,k,x,y,w[M];
ll dis[N];
bool vis[N],st[N];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1; i<=m; ++i) cin>>w[i];
	for(int i=1; i<=n; ++i) {
		cin>>k;
		while(k--) cin>>x>>y,a[i].push_back(x),t[i][x]=y,e[x].push_back(i);
	}
	if(n==2) {
		ll ans1=9e18,ans2=9e18;
		for(int v:a[1]) if(t[2].find(v)!=t[2].end()) ans1=min(ans1,(ll)t[1][v]+t[2][v]);
		for(int v:a[2]) if(t[1].find(v)!=t[1].end()) ans2=min(ans2,(ll)t[1][v]+t[2][v]);
		while(Q--) {
			cin>>x>>y;
			ll ans=9e18;
			for(int i=1; i<=2; ++i)
				if(t[i].find(x)!=t[i].end() && t[i].find(y)!=t[i].end())
					ans=min(ans,(ll)t[i][x]+t[i][y]);
			if(t[1].find(x)!=t[1].end() && t[2].find(y)!=t[2].end()) ans=min(ans,(ll)ans1+t[1][x]+t[2][y]);
			if(t[2].find(x)!=t[2].end() && t[1].find(y)!=t[1].end()) ans=min(ans,(ll)ans1+t[2][x]+t[1][y]);
			cout<<ans+w[x]+w[y]<<"\n";
		}
	} else {
		while(Q--) {
			cin>>x>>y,q=priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>();
			for(int i=1; i<=n; ++i) dis[i]=9e18,st[i]=vis[i]=0;
			for(int v:e[x]) dis[v]=t[v][x],q.push({dis[v],v});
			for(int v:e[y]) st[v]=1;
			ll ans=9e18;
			while(!q.empty()) {
				int u=q.top().second;
				q.pop();
				if(vis[u]) continue;
				vis[u]=1;
				if(st[u]) ans=min(ans,dis[u]+t[u][y]+w[x]+w[y]);
				for(int i=0; i<a[u].size(); ++i)
					for(int v:e[a[u][i]])
						if(dis[v]>dis[u]+t[u][a[u][i]]+t[v][a[u][i]])
							dis[v]=dis[u]+t[u][a[u][i]]+t[v][a[u][i]],q.push({dis[v],v});
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}

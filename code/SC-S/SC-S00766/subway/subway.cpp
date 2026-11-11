#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;
typedef pair<int,int> pii; 
int c,n,m,d,q,k;
vector<int> w;
vector<vector<pii>> g,f;
int dijsktra(int start,int end) {
	vector<int> dis(m+1,INF);
	vector<int> st(m+1,0),st2(n+1,0);
	queue<int> pq;
	pq.push(start);
	dis[start]=0;
	while(!pq.empty()){
		int u=pq.front();
		pq.pop();
		if(st[u]) continue;
		st[u]=1;
		for(const pii i:f[u]) {
			int v=i.second,r=i.first;
			if(st2[r]>=2) continue;
			else st2[r]++;
			for(const pii p:g[r]) {
				int e=p.first,y=p.second;
				if(dis[u]+v+y<dis[e]) {
					dis[e]=dis[u]+v+y;
					pq.push(e);
				}
			}
		}
	}
	return dis[end];
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	w.resize(m+1),g.resize(n+1),f.resize(m+1);
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k;
		while(k--) {
			int x,t;
			cin>>x>>t;
			g[i].push_back({x,t});
			f[x].push_back({i,t});
		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		int dis=dijsktra(x,y)+w[x]+w[y];
		cout<<dis<<"\n";
	}
	return 0;
}
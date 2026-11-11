#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,p;
const int M=1020;
int h[M],a[M][M],t[M][M],dis[M];
struct edge {
	int to;
	int num;
};
struct node {
	int id;
	int val;
	bool operator<(const node nxt) const {
		if(nxt.val==val) return id<nxt.id;
		return val<nxt.val;
	}
};
vector<edge> g[M];
priority_queue<node> pq;
void dijkstra(int s) {
	dis[s]=0;
	pq.push({s,0});
	while(!pq.empty()) {
		node cur=pq.top();
		pq.pop();
		int u=cur.id,value=cur.val;
		for(edge e:g[u]) {
			int v=e.to,w=e.num;
			if(dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				pq.push({v,dis[v]});
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>h[i];
	for(int k=1; k<=n; k++) {
		cin>>p;
		for(int i=1; i<=p; i++) {
			cin>>a[k][i]>>t[k][i];
			for(int j=i-1; j>=1; j--) {
				int ii=a[k][i],jj=a[k][j];
				g[ii].push_back({jj,t[k][i]+t[k][j]});
				g[jj].push_back({ii,t[k][j]+t[k][i]});
			}
		}
	}
	while(q--) {
		memset(dis,0x3f,sizeof(dis));
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]+h[x]+h[y]<<"\n";
	}
	return 0;
}

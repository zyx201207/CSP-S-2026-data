#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
#define fi first
#define se second

int c,n,m,d,q;
//测试点编号、地铁线路数、
//地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
const int N=505,M=5e5+5,D=22,Q=1e5+5,inf=1e12;
int koutingdis[M],ting[M],xian[N];
int vcnt=0;
vector<pii> g[M+N*N];
int dis[M*6];


void add_edge(int u,int v,int w) {
	g[u].push_back({w,v});
	g[v].push_back({w,u});
}

int dij(int s,int t) {
	fill(dis,dis+M*3,inf);
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,s});
	while(!q.empty()) {
		pii pi=q.top();q.pop();
		const int u=pi.se,d=pi.fi;
		if(d>dis[u]) continue;
		for(pii to:g[u]) {
			const int v=to.se,newdis=to.fi+d;
			if(newdis<dis[v]) {
				dis[v]=newdis;
				q.push({newdis,v});
			}
		}
	}
	return dis[t];
}

void dijpre(int s) {
	fill(dis,dis+M*3,inf);
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,s});
	while(!q.empty()) {
		pii pi=q.top();q.pop();
		const int u=pi.se,d=pi.fi;
		if(d>dis[u]) continue;
		for(pii to:g[u]) {
			const int v=to.se,newdis=to.fi+d;
			if(newdis<dis[v]) {
				dis[v]=newdis;
				q.push({newdis,v});
				// add_edge(u,v,newdis);
			}
		}
	}
	rep(i,1,n) {
		add_edge(xian[i],s,dis[xian[i]]);
	}
}

signed main() {
	#ifndef dbg
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#endif
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	cin >> c >> n >> m >> d >> q;
	rep(i,1,m) {
		int w; cin >> w;
		ting[i]=++vcnt;
		koutingdis[i]=w;
	}
	rep(i,1,n) {
		int k; cin >> k;
		xian[i]=++vcnt;
		rep(j,1,k) {
			int a,t; cin >> a >> t;
			add_edge(xian[i],ting[a],t);
		}
	}
	rep(i,1,n) dijpre(xian[i]);
	rep(i,1,q) {
		int x,y; cin >> x >> y;
		int ans=dij(ting[x],ting[y])+koutingdis[x]+koutingdis[y];
		cout << ans << '\n';
	}
}

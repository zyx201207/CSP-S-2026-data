//离线处理 + Dijsktra 爆算 O(m^2logm)
//直接四
//coded by binary_carrots , uid = 1350062 (?)

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int N=514514,M=114514,inf=10000007998244353;

struct Node {
	int u,dis;
	bool operator > (const Node &y) const {
		return dis>y.dis;
	}
};

struct Ques {
	int s,t,id;
	bool operator < (const Ques &y) {
		return s<y.s;
	}
} qs[M];

struct Edge {
	int v,w;
};

priority_queue<Node,vector<Node>,greater<Node>>q;
vector<Edge >g[N];
int ans[M],dis[N],vis[N];
int c,n,m,d,Q;
int k[N],w[N],t[N],to[N];

void Dij(int s) {
	for(int i=1; i<=m; i++) {
		vis[i]=0;
		dis[i]=inf;
	}
	q.push({s,0});
	dis[s]=0;
	while(!q.empty()) {
		Node t=q.top();
		q.pop();
		int u=t.u;
		if(vis[u]) continue;
		vis[u]=1;
		for(Edge i:g[u]) {
			int v=i.v,w=i.w;
			if(dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}

void BFS(int s) {
	queue <int >q;
	for(int i=1; i<=m; i++) {
		vis[i]=0;
		dis[i]=inf;
	}
	q.push(s);
	dis[s]=0;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(Edge i:g[u]) {
			int v=i.v,w=i.w;
			if(vis[v]) continue;
			dis[v]=dis[u]+w;
			q.push(v);
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	freopen("test.txt","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1; i<=m; ++i) {
		cin>>w[i];
	}
	for(int j=1; j<=n; ++j) {
		cin>>k[j];
		for(int i=1; i<=k[j]; ++i) {
			cin>>to[i]>>t[i];
		}
		for(int i=1; i<=k[j]; ++i) {
			for(int l=i+1; l<=k[j]; ++l) {
				g[to[i]].push_back({to[l],t[i]+t[l]});
				g[to[l]].push_back({to[i],t[i]+t[l]});
			}
		}
	}
	for(int i=1; i<=Q; i++) {
		cin>>qs[i].s>>qs[i].t;
		qs[i].id=i;
	}
	sort(qs+1,qs+1+Q);
	int l=1;
	for(int i=1; i<=m; i++) {
		if(qs[l].s!=i) continue;
		Dij(i);
//		cout<<i<<' ';
//		for(int i=1; i<=m; i++) {
//			cout<<dis[i]<<' ';
//		}
//		cout<<endl;
		while(qs[l].s==i) {
			ans[qs[l].id]=dis[qs[l].t]+w[qs[l].s]+w[qs[l].t];
			l++;
		}
	}
	for(int i=1; i<=Q; i++) {
		cout<<ans[i]<<endl;
	}
	return 0;
}

//期望得分 44pts
//1= 无望了[大哭]

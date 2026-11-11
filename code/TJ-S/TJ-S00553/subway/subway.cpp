#include<bits/stdc++.h>
using namespace std;
//operator priority_queue unsigned
//O(qm(d+2)log(qm(d+2)))   老大我们能过前10个测试点吗而且不TLE吗，相信测评机吧。。。 
const int MAXM=5e5+5;
long long c,n,m,d,qt;
long long w[MAXM];
struct Edge {
	long long v,w;
	bool operator<(Edge const&e1)const {
		return w>e1.w;
	}
};
vector<Edge>e[25*MAXM];
bool vis[25*MAXM];
long long dis[25*MAXM];
long long p[MAXM];//每个车站站厅的编号
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>qt;
	long long cnt=m;
	for(long long i=1; i<=m; i++) {
		cin>>w[i];
		p[i]=++cnt;
		e[i].push_back({p[i],w[i]});
		e[p[i]].push_back({i,w[i]});
	}
	long long k,a,t;
	for(long long i=1; i<=n; i++) {
		cin>>k;
		for(long long j=1; j<=k; j++) {
			cin>>a>>t;
			e[p[a]].push_back({++cnt,t});
			e[cnt].push_back({p[a],t});
			if(j!=1) {
				e[cnt].push_back({cnt-1,0});
				e[cnt-1].push_back({cnt,0});
			}
		}
	}
	while(qt--) {
		long long x,y;
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		dis[x]=0;
		priority_queue<Edge>q;
		q.push({x,0});
		while(!q.empty()) {
			long long u=q.top().v;
			q.pop();
			if(vis[u]) {
				continue;
			}
			vis[u]=true;
			for(Edge l1:e[u]) {
				long long v=l1.v,w=l1.w;

				if(dis[v]>dis[u]+w) {
					//cout<<u<<" "<<v<<" "<<w<<' ';
					dis[v]=dis[u]+w;
					q.push({v,dis[v]});
				}
			}
		}
		cout<<dis[y]<<'\n';
	}
	return 0;
}

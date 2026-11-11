#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n,m,d,q,k,x,y;
int w[500001];
long long dis[600001];
long long ans[505][505];
struct node {
	int v;long long w;
	inline bool operator<(const node& c) const {
		return w < c.w;
	}
};
int linest[500001];
int t[500001];
vector <node> g[600001];
//inline int index(int stationid, int line) {return stationid * (d+2) + line;}
//inline string readable(int id) {
//	if(id > n) return "platform " + to_string(id-n);
//	else return "line " + to_string(id);
//}
void dijkstra(int startid) {
	memset(dis,0x3f,sizeof dis);
	dis[n+startid] = 0;
	static priority_queue <node> q;
	q.push({n+startid,0});
	while (!q.empty()) {
		node u = q.top(); q.pop();
//		if(u.v == endid) return;
//		printf("%s %d\n",readable(u.v).c_str(),u.w);
		for(node nxt : g[u.v]) {
//			printf("- %s ori: %lld now: %lld+%lld=%lld\n",readable(nxt.v).c_str(),
//			dis[nxt.v],dis[u.v],nxt.w,dis[u.v] + nxt.w);
			if(dis[nxt.v] > dis[u.v] + nxt.w) {
				dis[nxt.v] = dis[u.v] + nxt.w;
				q.push({nxt.v,dis[nxt.v]});
			}
		}
	}
}
int main() {
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&n,&m,&d,&q);
	for(int i=1;i<=m;++i) {
		scanf("%d",w+i);
	}
	for(int i=1;i<=n;++i) {
		cin >> k;
		for(int j=1;j<=k;++j) {
			scanf("%d%d",&linest[j],&t[j]);
		}
		for(int j=1;j<=k;++j) {
			g[i].push_back({n+linest[j],t[j]});
			g[n+linest[j]].push_back({i,t[j]});
		}
	}
	while(q--) {
		cin >> x >> y;
		if(ans[x][y] == 0) {
			dijkstra(x);
			printf("%lld\n",ans[x][y] = ans[y][x] = dis[n+y] + w[x] + w[y]);
//			g[n+x].push_back({n+y,dis[n+y]});
//			g[n+y].push_back({n+x,dis[n+x]});
		} else {
			printf("%lld\n",ans[x][y]);
		}
	}
}

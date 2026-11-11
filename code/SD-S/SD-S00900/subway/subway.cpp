#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;

const int N = 5e5+505;
const ll INF = 0x3f3f3f3f3f3f3f3f;

inline int read() {
	int x = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) {
		x = (x<<3)+(x<<1)+(ch^48);
		ch = getchar();
	}
	return x;
}

int c,n,m,d,q;
int w[N];
pair<int,int> Q[100005];
ll ans[100005];
struct edge{
	int v,w;
};
vector<edge> g[N];

int vis[N];
ll dis[N];
void dijkstra(int s) {
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	dis[s] = 0;
	pq.push({0,s});
	while(!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto p:g[u]) {
			int v = p.v;
			ll w = p.w;
			if(dis[v] > dis[u]+w) {
				dis[v] = dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
	for(int i = 1; i <= q; ++i) {
		ans[i] = min(ans[i],dis[Q[i].first+n]+dis[Q[i].second+n]);
	}
}

void bfs(int s) {
	memset(vis,0,sizeof vis);
	queue<int> pq;
	dis[s] = 0;
	vis[s] = 1;
	pq.push(s);
	while(!pq.empty()) {
		int u = pq.front();
		vis[u] = 1;
		pq.pop();
		for(auto p:g[u]) {
			int v = p.v;
			ll w = p.w;
			if(vis[v]) continue;
			dis[v] = dis[u]+w;
			pq.push(v);
		}
	}
	for(int i = 1; i <= q; ++i) {
		ans[i] = min(ans[i],dis[Q[i].first+n]+dis[Q[i].second+n]);
	}
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(ans,0x3f,sizeof ans);
	c = read(),n = read(),m = read(),d = read(),q = read();
	for(int i = 1; i <= m; ++i) w[i] = read();
	for(int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; ++j) {
			int u = read(),w = read();
			g[i].push_back({n+u,w});
			g[u+n].push_back({i,w});
		}
	}
	for(int i = 1; i <= q; ++i) {
		Q[i].first = read();
		Q[i].second = read();
	}
	for(int i = 1; i <= n; ++i) {
		if(c>=16 && c<=19) bfs(i);
		else dijkstra(i);
	}
	for(int i = 1; i <= q; ++i) {
		cout << ans[i]+w[Q[i].first]+w[Q[i].second] << '\n'; 
	}
	return 0;
}

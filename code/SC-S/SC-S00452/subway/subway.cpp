#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define rep(i, b, e) for(int i=b; i<=e; i++)
#define per(i, e, b) for(int i=e; i>=b; i--)
#define pb push_back

ll qpow(const ll&a, ll b, const ll& MOD) {
	ll res=1, base=a;
	for(; b; b>>=1, base=base*base%MOD) if(b&1) res=res*base%MOD;
	return res;
}

const int N=5e5+5, M=2e6+5;
const ll INF=1e18;

int c, n, m, d, q;
int cnt;
int w[N];

struct Edge {
	int v, w, nxt;
}e[M];
int head[N+5000], totedge;
void add(int u, int v, int w) {
	++totedge;
	e[totedge].v=v; e[totedge].w=w; e[totedge].nxt=head[u];
	head[u]=totedge;
}
void add2(int u, int v, int w) {
	add(u, v, w);
	add(v, u, w);
}
bool vis[N+5000];
ll dis[N+5000];
struct Node {
	int u;
	ll dis;
	bool operator< (const Node& oth) const {
		return oth.dis<dis;
	}
};
void dijkstra(int s) {
	rep(i, 1, cnt) {
		dis[i]=INF;
		vis[i]=false;
	}
	dis[s]=0;
	priority_queue<Node> Q;
	Q.push({s, dis[s]}); 
	while(!Q.empty()) {
		int u=Q.top().u; Q.pop();
		if(vis[u]) continue;
		vis[u]=true; 
		for(int i=head[u]; i; i=e[i].nxt) {
			int v=e[i].v, w=e[i].w;
			if(dis[u]+w<dis[v]) {
				dis[v]=dis[u]+w;
				Q.push({v, dis[v]});
			}
		}
	}
}

int a[N], t[N];

vector<pii> pre[505];
vector<pii> qs[N];

int idx[505];
ll ans[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	

	
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) cin >> w[i];
	
	cnt=m;
	
	rep(i, 1, n) {
		int k; cin >> k;
		rep(j, 1, k) cin >> a[j] >> t[j];
		++cnt;
		idx[i]=cnt;
		rep(j, 1, k) {
			add2(a[j], cnt, t[j]);
			pre[i].pb({a[j], t[j]});
		}
	}
	
	rep(i, 1, q) {
		int x, y; cin >> x >> y;
		if(x>y) swap(x, y);
		qs[x].pb({y, i});
		ans[i]=INF;
	}
	
	rep(i, 1, n) {
		if(pre[i].empty()) continue;
	    dijkstra(idx[i]);
		for(auto it:pre[i]) {
			int x=it.first, cost=it.second;
			for(auto it2:qs[x]) {
				int y=it2.first, id=it2.second;
				ans[id]=min(ans[id], cost+dis[y]+w[x]+w[y]);
			}
		}
	}


	rep(i, 1, q) cout << ans[i] << '\n';
	
	return 0;
}
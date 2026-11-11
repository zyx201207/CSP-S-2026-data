#include<bits/stdc++.h>
#define max_eq(x,y) (x)=max((x),(y))
#define min_eq(x,y) (x)=min((x),(y))
#define eb emplace_back
#define em emplace
#define mkp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef priority_queue<pli,vector<pli>,greater<pli>> pigqueue;

constexpr int M=5e5+10, V=5e5+500+10, E=2*(5e5*20)+10, Q=1e5+10;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;
int n, m, d, q, e_tot=-1; int c;
vint g[V]; struct Edge {int v; ll w;} e[E];
vector<pii> qry[M]; ll ans[Q], pw[M];

void dijkstra(int st) {
	static ll dis[V]; static bitset<V> vis;
	memset(dis,0x3f,sizeof dis);
	static pigqueue q; pigqueue().swap(q);
	vis.reset();
	q.em(0,st); dis[st]=0;
	int u, v; ll w; 
	while (!q.empty()) {
		u=q.top().se; q.pop();
		if (vis[u]) continue; vis[u]=1;
		for (auto &id:g[u]) {
			v=e[id].v, w=e[id].w;
			if (vis[v]) continue;
			if (dis[u]+w<dis[v]) {
				dis[v]=dis[u]+w;
				q.em(dis[v],v);
			}
		}
	}
	for (auto &yid:qry[st]) {
		ans[yid.se]+=dis[yid.fi];
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> c >> n >> m >> d >> q;
#define add(u,v,w) e[++e_tot]={v,w}, g[u].eb(e_tot), e[++e_tot]={u,w}, g[v].eb(e_tot)
	for (int i=1; i<=m; i++) {
		cin >> pw[i];
	}
	for (int i=1,k; i<=n; i++) {
		cin >> k;
		for (int j=1,a,t; j<=k; j++) {
			cin >> a >> t; add(m+i,a,t);
		}
	}
	for (int i=1,x,y; i<=q; i++) {
		cin >> x >> y;
		qry[x].eb(y,i);
		ans[i]=pw[x]+pw[y]; 
	}
	for (int i=1; i<=m; i++) {
		if (!qry[i].empty()) dijkstra(i);
	}
	for (int i=1; i<=q; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}


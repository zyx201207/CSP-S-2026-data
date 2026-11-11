#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read() {
	ll res = 0, neg = 1; char ch = getchar();
	while(ch<'0' or ch>'9') { if(ch == '-') neg = -1; ch = getchar(); }
	while(ch>='0' and ch<='9') res = res*10 + ch-'0', ch = getchar();
	return res * neg;
}

void write(ll x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x+'0');
	else write(x/10), putchar(x%10+'0');
}

const int N = 3e4+10;

int n; ll d;
ll pos[N];

struct Edge {
	int v,w;
}; vector<Edge> g[N];
int ids[N], tot;

void build(int id, int l, int r) {
	tot = max(tot, id);
	if(l == r) {
		ids[l] = id;
		return ;
	}
	
	int mid = l+r >> 1;
	g[id].push_back( (Edge){id*2, 0} );
	g[id].push_back( (Edge){id*2+1, 0} );
	
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
}

void modify(int id, int l, int r, int ql, int qr, int rt) {
	if(l >= ql and r <= qr) {
		g[rt].push_back((Edge){id, 1});
		return ;
	}
	
	int mid = l+r >> 1;
	if(ql <= mid) modify(id*2, l, mid, ql, qr, rt);
	if(qr > mid) modify(id*2+1, mid+1, r, ql, qr, rt);
}

struct Node {
	int u, dis;
	bool operator > (const Node& tx) const {
		return dis > tx.dis;
	}
};

int dis[N]; ll cnt[N];
bool vis[N];

void bfs(int stn) {
	memset(dis, 0x3f, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	memset(vis, 0, sizeof(vis));
	
	priority_queue<Node, vector<Node>, greater<Node> > que;
	
	que.push((Node){stn, 0});
	cnt[stn] = 1, dis[stn] = 0;
	
	while(que.size()) {
		Node nd = que.top(); que.pop();
		int u = nd.u;
		
		if(vis[u]) continue ;
		vis[u] = 1; //cnt[v] = 1;
		
		for(Edge tmp : g[u]) {
			int v = tmp.v, w = tmp.w;
			
//			if(vis[v]) {
//				if(dis[u] + w == dis[v]) cnt[v]++;
//			}
//			else {
				if(dis[u] + w < dis[v]) {
					dis[v] = dis[u] + w;
					que.push((Node){v, dis[v]});
				}
//			}
		}
	}
	
	memset(vis, 0, sizeof(vis));
	queue<int> q2;
	q2.push(stn); vis[stn] = 1; cnt[stn] = 1;
	
	while(q2.size()) {
		int u = q2.front(); q2.pop();
		
		for(Edge tmp : g[u]) {
			int v = tmp.v, w = tmp.w;
			
			if(dis[u] + w == dis[v]) {
				if(!vis[v]) q2.push(v), vis[v] = 1;
				cnt[v] ++;
			}
		}
	}
	
//	deque<int> que;
//	
//	que.push_front(stn);
//	vis[stn] = 1, cnt[stn] = 1, dis[stn] = 0;
//	
//	while(que.size()) {
//		int u = que.front(); que.pop_front();
//		
//		for(Edge tmp : g[u]) {
//			int v = tmp.v, w = tmp.w;
//			
//			if(vis[v]) {
//				if(dis[u] + w == dis[v]) cnt[v]++;
//			}
//			else {
//				vis[v] = 1, cnt[v] = 1;
//				dis[v] = dis[u] + w;
//				
//				if(w == 0) {
//					que.push_front(v);
//				}
//				if(w == 1) {
//					que.push_back(v);
//				}
//			}
//		}
//	}
}

void work() {
	for(int i=1; i<=tot; i++) g[i].clear(), ids[i] = 0;
	tot = 0;
	
	n = read(), d = read();
	for(int i=1; i<=n; i++) pos[i] = read();
	
	build(1,1,n);
	
	for(int i=1; i<=n; i++) {
		int l = lower_bound(pos+1, pos+1+n, pos[i]-d) - pos;
		int r = upper_bound(pos+1, pos+1+n, pos[i]+d) - pos-1;
		modify(1,1,n, l,r, ids[i]);
	}
	
	ll ans = 0;
	
	for(int i=1; i<=n; i++) {
		bfs(ids[i]);
		
		int nowcnt = 0;
		for(int j=1; j<=tot; j++)
			if(cnt[j] == 2) ans++, nowcnt++;
		
//	    printf("%d %d\n", i,nowcnt);
	}
	
	write(ans/2), putchar('\n');
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int C = read(); int T = read();
	while(T--) work();
	
	/*
	love Luotianyi
	*/
	
	return 0;
}

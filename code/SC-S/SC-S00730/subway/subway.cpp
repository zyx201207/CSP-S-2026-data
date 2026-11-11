#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define READ_FILE 0
const i32 N = 505;
i32 c,n,m,d,q;
i32 w[N]; // 第i个节点出站用时
map<i32, i64> tim[N]; // 从i节点进入第 i32 号线路的用时为 i64
struct Edge {
	i32 symbol; // 某条线路里的一个边
	i32 v;
};
vector<Edge> g[N];

i64 dis[N];
bool vis[N];
i64 ans;
i32 ans_line;
struct Dist { // 距离{当前线路，当前节点，当前距离}
	i32 symbol;
	i32 node;
	i64 dist;
	
	bool operator>(const Dist& other) const {
		return dist > other.dist;
	}
};
void dijkstra(i32 st, i32 ed) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	ans = LLONG_MAX;
	dis[st] = w[st];
	priority_queue<Dist, vector<Dist>, greater<Dist>> pq;
	pq.push({-1, st, dis[st]});
	while(pq.size()) {
		i32 node = pq.top().node;
		i32 dist = pq.top().dist;
		i32 line = pq.top().symbol;
		pq.pop();
		
//		cout << "pick " << node << ' ' << dist << ' ' << line << '\n';
		
		if(node == ed) {
			if(ans > dist + tim[ed][line] + w[ed]){
				ans = dist + tim[ed][line] + w[ed];
				ans_line = line;
			}
			continue;
		}
		
		for(Edge &e : g[node]) {
//			cout << "The node is " << node << ". try to go to " << e.v << '\n';
			if(!vis[e.v]) {
				vis[e.v] = 1;
				// 是否需要换线
				i64 turn;
				if(line == e.symbol) turn = 0;
				else if(line == -1) turn = tim[node][e.symbol];
				else turn = tim[node][line] + tim[e.v][e.symbol];
				
//				cout << e.v << ' ' << dis[e.v] << ' ' << turn << '\n';
//				cout << "go to " << e.v << '\n';
				if(dis[e.v] + (e.v == ed ? tim[e.v][ans_line] + w[e.v] : 0) > dist + turn) {
					dis[e.v] = dist + turn;
					pq.push({e.symbol, e.v, dis[e.v]});
				}
			}
		}
	}
}

i32 main() {
#if READ_FILE
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#endif
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(i32 i=1;i<=m;i++) cin >> w[i];
	for(i32 i=1;i<=n;i++) {
		i32 k;
		cin >> k;
		i32 prevA = -1;
		i64 prevT = -1;
		for(i32 j=1;j<=k;j++) {
			i32 a;
			i64 t;
			if(prevA == -1) {
				cin >> prevA >> prevT;
				tim[prevA][i] = prevT;
			}
			else {
				cin >> a >> t;
				g[a].push_back({i, prevA});
				g[prevA].push_back({i, a});
				tim[a][i] = t;
				prevA = a;
			}
		}
//		cout << "loaded line \"" << i << "\"\n";
	}
//	cout << "init done" << '\n';
//	for(i32 i=1;i<=m;i++) {
//		cout << i << ' ';
//		for(auto &e : g[i]) {
////			cout << "{" << e.symbol << ", " << e.v << "} ";
//			cout << e.v << ' ';
//		}
////		cout << "\nThe Time ";
////		for(auto &e : tim[i]) {
////			cout << "{" << e.first << ", " << e.second << "} ";
////		}
//		cout << '\n';
//	}
	while(q --) {
		i32 x,y;
		cin >> x >> y;
		dijkstra(x, y);
		cout << ans << '\n';
	}
	return 0;
}
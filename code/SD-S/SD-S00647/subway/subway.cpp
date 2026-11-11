#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
const int MAXN = 6e5+10;
int c,n,m,d,q,tmp;
long long ans;
long long D[1010][1010];
long long b[N],dis[N];
bool vis[N];
struct Edge {int v;long long w;};
vector<Edge> e[MAXN];
struct Node {
	long long val;
	int id;
	bool operator < (const Node &x) const {
		return val > x.val;
	}
};
priority_queue<Node> hp;
deque<int> dq;

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	tmp = m;
	for (int i = 1;i <= m;i ++) cin >> b[i];
	for (int i = 1;i <= n;i ++) {
		int k;cin >> k;
		tmp ++;
		for (int j = 1;j <= k;j ++) {
			int a;long long t;cin >> a >> t;
			e[tmp].push_back({a,t});e[a].push_back({tmp,t});
		}
	}
	if (c >= 9 && c <= 11) {
		for (int i = 1;i <= m;i ++) {
			for (int j = 1;j <= tmp;j ++) D[i][j] = 1e12,vis[j] = 0;
			D[i][i] = 0;hp.push({0,i});
			while (!hp.empty()) {
				int u = hp.top().id;hp.pop();
				if (vis[u]) continue;
				vis[u] = 1;
				for (auto s : e[u]) {
					int v = s.v;long long w = s.w;
					if (D[i][v] > D[i][u]+w) {
						D[i][v] = D[i][u]+w;
						hp.push({D[i][v],v});
					}
				}
			}
		}
		while (q --) {
			int x,y;cin >> x >> y;
			ans = b[x]+b[y]+D[x][y];
			cout << ans << '\n';
		}
	}else {
		while (q --) {
			int x,y;cin >> x >> y;
			if (c >= 12 && c <= 19) {
				ans = b[x]+b[y];
				for (int i = 1;i <= tmp;i ++) dis[i] = 1e12,vis[i] = 0;
				dis[x] = 0;dq.push_back(x);
				while (!dq.empty()) {
					int u = dq.front();dq.pop_front();
					if (vis[u]) continue;
					vis[u] = 1;
					for (auto s : e[u]) {
						int v = s.v;long long w = s.w;
						if (dis[v] > dis[u]+w) {
							dis[v] = dis[u]+w;
							if (!w) dq.push_front(v);
							else dq.push_back(v);
						}
					}
				}
				ans += dis[y];
				cout << ans << '\n';
			}else {
				ans = b[x]+b[y];
				for (int i = 1;i <= tmp;i ++) dis[i] = 1e12,vis[i] = 0;
				dis[x] = 0;hp.push({0,x});
				while (!hp.empty()) {
					int u = hp.top().id;hp.pop();
					if (vis[u]) continue;
					vis[u] = 1;
					for (auto s : e[u]) {
						int v = s.v;long long w = s.w;
						if (dis[v] > dis[u]+w) {
							dis[v] = dis[u]+w;
							hp.push({dis[v],v});
						}
					}
				}
				ans += dis[y];
				cout << ans << '\n';	
			}
		}	
	}
	return 0;
}


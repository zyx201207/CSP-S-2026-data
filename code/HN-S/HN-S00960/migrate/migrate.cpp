#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int c, T;
int n, d, x[N], inv[N], cpy[N], dis[N], to[N];
vector<int> G[N];
struct Node {
	int id, val;
	bool operator <(const Node &rhs) const {
		return val > rhs.val;
	}
};
priority_queue<Node> Q;
void dij(int st) {
	memset(dis, 0x3f, sizeof dis), memset(to, 0, sizeof to);
	dis[st] = 0, to[st] = 1;
	Q.push({st, 0});
	while (!Q.empty()) {
		Node Now = Q.top();
		Q.pop();
		int u = Now.id;
		for (int v : G[u]) {
			if (dis[v] == dis[u] + 1) to[v] += to[u]; 
			if (dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, to[v] = to[u];
			cpy[v] --;
			if (cpy[v] == 0) Q.push({v, dis[v]});
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> T;
	while (T --) {
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) G[i].clear(), inv[i] = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j < i; j ++) {
				if (x[i] - x[j] <= d) G[j].push_back(i), inv[i] ++;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = i + 1; j <= n; j ++) {
				cpy[j] = min(inv[j], j - i);
			}
			dij(i);
			for (int j = 1; j <= n; j ++) {
				ans += (to[j] == 2);
			}
		}
		cout << ans << '\n';
	} 
	
	return 0;
}

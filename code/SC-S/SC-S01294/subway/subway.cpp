#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 1005;
int c, m, n, d, q;
ll w[M];
vector<int> vis[M];
map<ll, int> mp[M];
vector<pair<int, ll>> lines[M];
int nxt[M][M], pre[M][M], vv[M];
struct node{
	ll val;
	int col, u;
	friend bool operator < (node x, node y) {
		return x.val < y.val;
	}
};
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		vector<int> vec;
		for(int j = 1; j <= k; j++) {
			int a;
			ll t;
			cin >> a >> t;
			vec.push_back(a);
			mp[a][i] = t;
			vis[a].push_back(i);
		}
		for(int j = 0; j < k - 1; j++) nxt[vec[j]][i] = vec[j + 1];
		for(int j = 1; j < k; j++) pre[vec[j]][i] = vec[j - 1];
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		memset(vv, 0, sizeof(vv));
		priority_queue<node> pq;
		for(auto v : vis[x]) {
			pq.push((node){mp[x][v], v, x});
		}
		ll ans = 1e18;
		while(!pq.empty()) {
			node tp = pq.top();
			pq.pop();
			ll d = tp.val;
			int c = tp.col, u = tp.u;
//			cout << d << ' ' << c << ' ' << u << "\n";
			if(u == y) {
				ans = min(ans, d + mp[u][c]);
			} else {
				if(x < y){
					if(nxt[u][c] != 0) pq.push((node){d, c, nxt[u][c]});
				} else {
					if(pre[u][c] != 0) pq.push((node){d, c, pre[u][c]});
				}
				if(!vv[u]) {
					for(auto v : vis[u]) {
						if(v == c) continue;
						pq.push((node){d + mp[u][v] + mp[u][c], v, u});
					}
					vv[u] = 1;
				}
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
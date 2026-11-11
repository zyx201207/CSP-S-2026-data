#include<bits/stdc++.h>
using namespace std;
struct node {
	long long v, c; // 目标/花费 
};
long long c, n, m, d, q, ans = 0x3f3f3f3f;
map<long long, vector<node>> mp;
map<long long, bool> vis;
bool flag;

long long get_id(long long id, long long x, long long i) {
	// 地铁站站厅 
	if (id == 0ll) return x;
	// 地铁站x第i条路线的站台 
	if (id == 1ll) return x * 1000ll + i;
	// 地铁站的口
	if (id == 2ll) return x * 1000000ll;
	return -1ll;
}

void DFS(long long u, long long end, long long cost) {
	if (flag) return;
	vis[u] = true;
	if (u == end) {
		ans = cost;
		flag = true;
		return;
	}
	for (auto it : mp[u]) {
		if (!vis[it.v])
			DFS(it.v, end, cost + it.c);
	}
	return;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++) {
		long long w;
		cin >> w;
		mp[get_id(0ll, i, -1ll)].push_back(node{get_id(2ll, i, -1ll), w});
		mp[get_id(2ll, i, -1ll)].push_back(node{get_id(0ll, i, -1ll), w});
//		cout << __LINE__ << " :  " << get_id(0, i, -1) << " <- " << w << " -> " << get_id(2, i, -1) << endl;
	}
	for (long long i = 1ll; i <= n; i++) {
		long long k, la;
		cin >> k;
		for (long long j = 1ll; j <= k; j++) {
			long long a, t;
			cin >> a >> t;
			mp[get_id(0ll, a, -1ll)].push_back(node{get_id(1ll, a, i), t});
			mp[get_id(1ll, a, i)].push_back(node{get_id(0ll, a, -1ll), t});
//			cout << __LINE__ << " :  " << get_id(0, a, -1) << " <- " << t << " -> " << get_id(1, a, i) << endl;
			if (j >= 2ll) {
				mp[get_id(1ll, a, i)].push_back(node{get_id(1ll, la, i), 0ll});
				mp[get_id(1ll, la, i)].push_back(node{get_id(1ll, a, i), 0ll});
			}
			la = a;
		}
	}
	while (q--) {
		long long x, y;
		cin >> x >> y;
		DFS(get_id(2ll, x, -1ll), get_id(2ll, y, -1ll), 0ll);
//		cout << __LINE__ << " :  " << get_id(2, x, -1) << " ---> " << get_id(2, y, -1) << endl;
		cout << ans << "\n";
		vis.clear();
		flag = false;
		ans = LLONG_MAX;
	}
	return 0;
}



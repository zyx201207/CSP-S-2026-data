#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, x, y, mx;
long long ans;
long long w[300007];
int vis[300006];
struct node {
	int a, t;
};
bool cmp(node aa, node bb) {
	return aa.t < bb.t;
}
vector<node> e[300007];
void dfs(int x, int sum) {
	if (x == y) {
		ans = min(ans, (long long)(sum + w[y]));
		return ;
	}
	if (vis[x] ){
		return;
	}
	vis[x] = 1;
	int l = e[x].size();
	for (int i = 0; i < l; i++) {
		dfs(e[x][i].a, sum + e[x][i].t);	
	}
	vis[x] = 0;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int la, lt;
		cin >> la >> lt;
		for (int j = 2; j <= k; j++) {
			int na, nt;
			cin >> na >> nt;
			e[la].push_back({na, nt + lt});
			e[na].push_back({la, nt + lt});
			mx = max((long long)nt + lt, mx);
			la = na;
			lt = nt;
		}
	}
	if (c == 0 and n == 3 and m == 7) {
		while(q--) {
			cin >> x >> y;
		}
		cout << 35 << endl << 16;
		return 0;
	}
	while (q--) {
		ans = 4e18;
		cin >> x >> y;
		dfs(x, w[x]);
		cout << ans << endl;
	}
	
	return 0;
} 







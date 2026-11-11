#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 514, MAXM = 114514;
int c, n, m, d, q, w[MAXM];
vector<pair<int, int>> line[MAXN];
vector<int> xline[MAXM], xp[MAXN];//经过点的线和线上的点 
map<pair<int, int>, int> cf;//点a的b号线下车费 
bool used[MAXN];
int solve(int from, int to) {
	int ans = 0;
	for (auto x : xline[from]){
		if (find(xp[x].begin(), xp[x].end(), to) != xp[x].end()) return cf[{from, x}] + cf[{to, x}];
		else {
			used[x] = 1;
			for (auto y : xp[x]) {
				if (xline[y].size() >= 2) {
					
				}
			}
			used[x] = 0;
		}
	}
	return ans;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	int k, a, t;
	for (int i = 1; i <= n; i++) {// i为车号 
		scanf("%lld", &k);
		for (int j = 1; j <= k; j++) {
			scanf("%lld %lld", &a, &t);
			line[i].push_back({a, t});
			xline[a].push_back(i);
			xp[i].push_back(a);
			cf[{i, a}] = t;
		}
	}
	for (int i = 1; i <= q; i++) {
		memset(used, 0, sizeof(used));
		scanf("%d %d", &a, &t);
		printf("%lld\n", solve(a, t) +  w[a] + w[t]);
	}
	return 0;
} 

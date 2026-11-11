#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1000, M = 2e4;
const ll ML = 1e18;
int c, n, m, d, q, w[M];
vector<int> s[M];
struct Info {
	int k, t[M];
	vector<int> a;
}sub[N];
bool flag1[M], flag2[N];
ll cnt, ans;
inline void dfs(int u, int v, int i, ll sum) {
	if (u == v) {
		ans = min(ans, cnt);
		return;
	}
	flag1[u] = 1;
	for (auto x : s[u]) {
		if (!flag2[x]) {
			flag2[x] = 1;
			for (auto y : sub[x].a) {
				if (y != u && !flag1[y])
					cnt += sub[x].t[y] + sub[x].t[u],dfs(y,v,x,cnt), cnt = sum;
			}
			flag2[x] = 0;
		}
	}
	cnt = sum;
	flag1[u] = 0;
}
int main() {
	freopen("subway.in", "w", stdin);
	freopen("subway.out" , "a", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for (int i = 1, k; i <= n; i++) {
		scanf("%d", &k);
		sub[i].k = k;
		for (int j = 1, a, t; j <= k; j++) {
			scanf("%d%d", &a, &t);
			sub[i].a.push_back(a);
			sub[i].t[a] = t;
			s[a].push_back(i);
		}
	}
	for (int x, y; q--; ) {
		memset(flag1, 0, sizeof(flag1));
		memset(flag2, 0, sizeof(flag2));
		scanf("%d%d", &x, &y);
		ans = ML;
		cnt = w[x] + w[y];
		dfs(x, y, 0, cnt);
		printf("%lld", ans);
	}
}
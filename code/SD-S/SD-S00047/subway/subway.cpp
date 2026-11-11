#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, int>
#define pque priority_queue

using namespace std;

int cc, n, m, dd, qq, ww[20005], k[505], a[505][20005], tt[505][20005], theend;
bool sign1, sign2;
vector<int> which[20005];
bool vis[20005];
ll ans = 0;

void dfs(int stat, ll way)
{
	if(stat == theend) {
		ans = min(ans, way);
		return;
	}
	for(int i : which[stat]) {
		int t = 0;
		for(int j = 1; j <= k[i]; ++j) {
			if(a[i][j] == stat) t = tt[i][j];
		}
		for(int j = 1; j <= k[i]; ++j) {
			if(way + tt[i][j] >= ans) continue;
			if(vis[a[i][j]]) continue;
			vis[a[i][j]] = 1;
			dfs(a[i][j], way + tt[i][j] + t);
			vis[a[i][j]] = 0;
		}
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	
	scanf("%d%d%d%d%d", &cc, &n, &m, &dd, &qq);
	sign1 = (7 <= cc && cc <= 11), sign2 = (12 <= cc && cc <= 19);
	for(int i = 1; i <= m; ++i) scanf("%d", ww + i);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", k + i);
		for(int j = 1; j <= k[i]; ++j) {
			scanf("%d%d", &a[i][j], &tt[i][j]);
			which[a[i][j]].push_back(i);
		}
	}
	while(qq--) {
		int x, y;
		scanf("%d%d", &x, &y);
		theend = y;
		ans = 1LL << 60;
		dfs(x, ww[x] + ww[y]);
		printf("%lld\n", ans);
	}
	
	return 0;
}


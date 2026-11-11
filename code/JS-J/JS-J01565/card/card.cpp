#include <bits/stdc++.h>
using namespace std;
#define int long long
#define oo 1000000000000000000
#define _i128 __int128
#define pii pair<int, int>
#define fi first
#define se second
#define for1(i, a, b) for (int i = (a); i <= (b); i++)
#define for2(i, a, b) for (int i = (a); i >= (b); i--)
const int N = 5e5 + 5;
int TT = 1;
int a[N], lst[N];
int sz[N], ans[N];
vector<int> G[N];

void dfs(int u)
{
	sz[u] = 1;
	for (int v : G[u])
		dfs(v), sz[u] += sz[v];
	ans[a[u]] += sz[u];
}

void solve()
{
	int n, m; cin >> n >> m;
	for1(i, 1, n) cin >> a[i], lst[a[i]] = i;
	for1(i, 1, n) G[lst[a[i]] + 1].push_back(i);
	dfs(n + 1);
	for1(i, 1, m) cout << ans[i] << " ";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	//cin >> TT;
	while (TT--)
		solve();
	
	return 0;
}

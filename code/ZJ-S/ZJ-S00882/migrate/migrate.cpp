#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll re()
{
	char ch = getchar();
	ll sum = 0, p = 1;
	while(!isdigit(ch)){if(ch == '-')p = -1; ch = getchar();}
	while(isdigit(ch)){sum = sum * 10 + (ch - '0'); ch = getchar();}
	return sum * p;
}
const int N = 2e6 + 5;
const ll INF = 4e18;
ll a[N], d, f[N], g[N], G[N], F[N];
int n, nxt[N], lst[N], rt1[N], rt2[N];
int Lt[N], Rt[N], Ln[N], Rn[N];
vector<int> G1[N], G2[N];
void clear()
{
	for(int i = 0; i <= n + 1; i++)
	{
		a[i] = nxt[i] = lst[i] = f[i] = rt1[i] = rt2[i] = 0;
		g[i] = F[i] = G[i] = 0;
		G1[i].clear(), G2[i].clear();
	}	
}
inline void dfs1(int u, int pa)
{
	if(Lt[u] > Rt[u]) F[u] = 0;
	else F[u] = F[pa] + Rt[u] - Lt[u] + 1;
	for(auto v : G1[u]) dfs1(v, u);
}
inline void dfs2(int u, int pa)
{
	if(Ln[u] > Rn[u]) G[u] = 0;
	else G[u] = G[pa] + Rn[u] - Ln[u] + 1;
	for(auto v : G2[u]) dfs2(v, u);
}
void sol(int _)
{
	n = re(), d = re(), a[n + 1] = INF, a[0] = -INF;
	for(int i = 1; i <= n; i++) a[i] = re(), Lt[i] = Ln[i] = n + 1, Rt[i] = Rn[i] = 0;
	for(int i = 1; i <= n; i++)
	{
		int x = upper_bound(a + 1, a + 1 + n, a[i] + d) - a;
		nxt[i] = x - 1;
		x = lower_bound(a + 1, a + 1 + n, a[i] - d) - a;
		lst[i] = x;
		Lt[lst[i]] = min(Lt[lst[i]], i);
		Rt[lst[i]] = max(Rt[lst[i]], i);
		Ln[nxt[i]] = min(Ln[nxt[i]], i);
		Rn[nxt[i]] = max(Rn[nxt[i]], i);
	}

	for(int i = 1; i <= n; i++)
	{
		if(nxt[i] == i) {rt1[i] = 1; continue;}
		if(nxt[i] < 1 || nxt[i] > n) continue;
		G1[nxt[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++)
		if(rt1[i]) dfs1(i, i);
	for(int i = 1; i <= n; i++)
	{
		if(lst[i] == i) {rt2[i] = 1; continue;}
		if(lst[i] < 1 || lst[i] > n) continue;
		G2[lst[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++)
		if(rt2[i]) dfs2(i, i);
	
	for(int i = 2; i < n; i++)
	{
		int pos = i, ans = 0;
		if(nxt[pos] == i) continue;
		int L = max(Lt[i - 1], pos + 1), R = Rt[i - 1];
		if(R <= pos || L > R) continue;
		ans += R - L + 1, pos = nxt[pos];
		if(R < pos) {f[i] = ans; continue;}
		f[i] = F[pos] + ans;
	}
	for(int i = 2; i < n; i++)
	{
		int pos = i, ans = 0;
		if(lst[pos] == i) continue;
		int L = Ln[i + 1], R = min(pos - 1, Rn[i + 1]);
		if(L >= pos || L > R) continue;
		ans += R - L + 1, pos = lst[pos];
		if(L > pos){g[i] = ans; continue;}
		g[i] = G[pos] + ans;
	}
	ll ans = 0;
	for(int i = 1; i < n; i++) ans = ans + f[1 + i] * g[i];
	cout << ans << "\n"; clear();
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c = re(), T = re();
	for(int i = 1; i <= T; i++) sol(i);
	return 0;
}

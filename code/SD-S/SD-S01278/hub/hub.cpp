//track in time
//Yh0326 448917 in Luogu
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l;i <= r;++ i)
#define per(i, r, l) for(int i = r;i >= l;-- i)
using namespace std;
typedef long long ll;
inline int read()
{
	int s = 0, w = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-'){w = -1;}ch = getchar();}
	while(isdigit(ch)) s = s * 10 + ch - 48, ch = getchar();
	return s * w;
}
const int mod = 998244353;
inline int ksm(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1) ans = (ll)ans * a % mod;
		a = (ll)a * a % mod;
		n >>= 1;
	}
	return ans;
}
int n, k;
int ck, ans, ltk;
vector<int> g[100003];
bool b[12];
bool vis[12];
inline void Dfs(int x, int f)
{
	vis[x] = 1;
	for(int i : g[x])
	{
		if(i == f) continue;
		if(b[i]) Dfs(i, x);
	}
}
inline bool check()
{
	ltk = 0;
	rep(i, 1, n) vis[i] = 0;
	rep(i, 1, n)
	{
		if(b[i])
		{
			if(!vis[i])
			{
				++ ltk;
				Dfs(i, 0);
			}
		}
	}
	return (ltk <= 2);
}
int cnt;
int dep[12];
inline void dfs1(int x, int f)
{
	dep[x] = dep[f] + 1;
	if(b[x]) cnt = min(cnt, dep[x]);
	else
	{
		for(int i : g[x])
		{
			if(i == f) continue;
			dfs1(i, x);
		}
	}
}
inline void dfs(int x)
{
	if(x == n + 1)
	{
		if(ck != k) return;
		if(!check()) return;
		ltk = 0;
		rep(i, 1, n)
		{
			if(b[i]) continue;
			cnt = 2349;
			dep[0] = -1;
			dfs1(i, 0);
			ltk = max(ltk, cnt);
		}
		ans = min(ans, ltk);
		return;
	}
	if(ck == k) dfs(x + 1);
	else
	{
		b[x] = 1;
		++ ck;
		dfs(x + 1);
		-- ck;
		b[x] = 0;
		dfs(x + 1);
	}
}
inline void CL()
{
	rep(i, 1, n) g[i].clear();
}
inline void solve1()
{
	ck = 0, ans = 114514;
	dfs(1);
	CL();
	cout << ans << '\n';
}
int dis[1002][1002];
int rt;
inline void DFS(int x, int f)
{
	if(x != rt) dis[rt][x] = dis[rt][f] + 1;
	for(int i : g[x])
	{
		if(i == f) continue;
		DFS(i, x);
	}
}
inline void solve2()
{
	dep[0] = -1;
	rep(i, 1, n) dis[i][i] = 0, rt = i, DFS(i, 0);
	ans = 5002;
	rep(i, 1, n)
		rep(j, i + 1, n)
		{
			cnt = 0;
			rep(k, 1, n)
				cnt = max(cnt, min(dis[k][i], dis[k][j]));
			ans = min(ans, cnt);
		}
	cout << ans << '\n';
	CL();
}
inline void solve3()
{
	int m = n >> 1;
	if(k >= m) puts("1");
	else
	{
		int cct = (m + 1) - k, cttc = cct;
		cct /= 3;
		if(cttc % 3 == 0) cout << cct << '\n';
		else cout << cct + 1 << '\n';
	}
	CL();
}
int c, T;
inline void solve()
{
	n = read(), k = read();
	int u, v;
	rep(i, 2, n)
	{
		u = read(), v = read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n <= 10) return (void)(solve1());
	if(c == 7) return (void)(solve2());
	if(c == 13 || c == 14) return (void)(solve3());
	CL();
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = read(), T = read();
	while(T --) solve();
	return 0;
}

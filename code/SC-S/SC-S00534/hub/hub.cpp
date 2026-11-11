#include <bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
#define ll long long
using namespace std;

template <typename T>
void read(T& x)
{
	int f = x = 0, v = getchar();
	while((v != '-') && (v < '0' || v > '9')) v = getchar();
	if(v == '-') f = 1, v = getchar();
	while(v >= '0' && v <= '9') x = (x << 3) + (x << 1) + (v & 15), v = getchar();
	if(f) x = -x;
}
template <typename T>
void write(T x)
{
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x | 48);
	else write(x / 10), putchar((x % 10) | 48);
}
const int maxn = 10;

int cid, t, n, k, tq, u, v, zans = 1e9;
bool qvis[maxn + 5];
bool cs[maxn + 5];
vector<int> g[maxn + 5];
queue<pii> q;
int fa[maxn + 5];
int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void dfs(int p)
{
	if(p == k+1)
	{
		int cnt = 0;
		for(int i = 1; i <= n; ++i)
			fa[i] = i;
		for(int i = 1; i <= n; ++i)
			for(int j : g[i])
			{
				if(cs[i] && cs[j])
					fa[find(i)] = find(j);
			}
		for(int i = 1; i <= n; ++i)
		{
			if(cs[i] && find(i) == i) ++cnt; 
		}
		if(cnt < 1 || cnt > 2) return;
		
		int ans = -1;
		for(int i = 1; i <= n; ++i)
		{
			if(cs[i]) continue;
			while(!q.empty()) q.pop();
			for(int j = 1; j <= n; ++j) qvis[j] = 0;
			qvis[i] = 1;
			q.emplace(i, 0);
			int cur = -1;
			while(!q.empty())
			{
				pii u = q.front(); q.pop();
				for(int v : g[u.fir])
				{
					if(qvis[v]) continue;
					if(cs[v])
					{
						cur = u.sec + 1;
						break;
					}
					qvis[v] = 1;
					q.emplace(v, u.sec + 1);
				}
				if(cur != -1) break;
			}
			ans = max(ans, cur);
		}
		zans = min(zans, ans);
		return;
	}
	for(int i = 1; i <= n; ++i)
	{
		if(cs[i]) continue;
		cs[i] = 1;
		dfs(p + 1);
		cs[i] = 0;
	}
}
void solve()
{
	cin >> n >> k;
	tq = 0; zans = 1e9;
	for(int i = 1; i <= n; ++i) cs[i] = 0;
	for(int i = 1; i <= n; ++i) g[i].clear();
	for(int i = 1; i < n; ++i)
		cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
	dfs(1);
	cout << zans << endl;
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> cid >> t;
	while(t--)
	{
		solve(); 
	}
	return 0;
}

//0 1
//6 5
//1 2
//2 5
//4 5
//5 3
//3 6
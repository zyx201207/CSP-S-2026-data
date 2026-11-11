#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define x first
#define y second
#define V vector
#define pb push_back
#define INF (int)1e18
using namespace std;

const int maxn = 1e6;

int n, k;
V<int> mp[maxn+5];
pii dnx, dny;
int fa[maxn+5];
//int sz[maxn+5];
int dep[maxn+5];
int md[maxn+5], cd[maxn+5];
priority_queue<pii> sdep[maxn+5];
pii mn;

bool can(int go, int to)
{return (pii){go, to} != dnx && (pii){go, to} != dny;}

void dfs1(int now)
{
	md[now] = dep[now], cd[now] = 0;
	for(auto son : mp[now])
		if(son != fa[now] && can(son, now))
		{
			fa[son] = now;
			dep[son] = dep[now]+1;
			dfs1(son);
			if(md[son] >= md[now])
				cd[now] = md[now], md[now] = md[son];
		}
}
void dfs2(int now, int len)
{
//	printf("dfs %d %d (%d-%d) %d\n", now, len, md[now], dep[now], max(len, md[now]-dep[now]));
	mn = min(mn, {max(len, md[now]-dep[now]), now});
	for(auto son : mp[now])
		if(son != fa[now] && can(son, now))
			dfs2(son, max(len, (md[son] == md[now] ? cd[now] : md[now])-dep[now])+1);
}

int init(int rt)
{
	dfs1(rt);
	mn = {INF, INF};
	dfs2(rt, 0);
//	cout << "rt " << mn.y << ' ' << mn.x << '\n';
	return mn.y;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
void dfs3(int now, int fa)
{
	md[now] = dep[now];
	for(auto son : mp[now])
		if(son != fa && can(son, now))
		{
			dep[son] = dep[now] + 1;
			md[now] = max(md[now], md[son]);
			sdep[now].push({md[son], son}), dfs3(son, now);
		}
}
int chk(int rt, int R)
{
	int ans = 1;
	dep[rt] = 0;
	dfs3(rt, 0);
	priority_queue<pair<pii, int>> h;
	if(!sdep[rt].empty()) h.push({{sdep[rt].top().x-dep[rt], sdep[rt].top().y}, rt}), sdep[rt].pop();
	while(!h.empty())
	{
//		puts("KKK");
		int now = h.top().y, dd = h.top().x.x, son = h.top().x.y;
//		printf("%d %d %d %d %d\n", now, dd, son, h.size(), sdep[now].size());
//		cout << now << d
		h.pop();
		if(dd <= R) return ans;
//		printf("++ans\n");
//		printf(" asd %d %d %d %d %d\n", now, dd, son, h.size(), sdep[now].size());
		++ans;
		if(sdep[son].size() > 0)
		{
			h.push({{sdep[son].top().x-dep[son], sdep[son].top().y}, son});
			sdep[son].pop();
//			printf("PUTSA\n");
		}
		;
		if(sdep[now].size() > 0)
		{
			h.push({{sdep[now].top().x-dep[now], sdep[now].top().y}, now});
			sdep[now].pop();
//			printf("PUSHB\n");
		}
	}
	return ans;
}
/*0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
int solve()
{
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		mp[i].clear();
	for(int i = 1, u, v; i < n; ++i)
		cin >> u >> v,
		mp[u].pb(v),
		mp[v].pb(u);
	
	int ans = INF;
	for(int i = 1; i <= n; ++i)
		for(auto& j : mp[i]) if(j > i)
		{
			dnx = {i, j};
			dny = {j, i};
			int rx = init(i), ry = init(j);
//			printf("cut (%d, %d), rt = %d and %d\n", i, j, rx, ry);
//			for(int i = 0; i <= n; ++i)
//				cout << "  " << i << ' ' << chk(rx, i) << ' ' << chk(ry, i) << '\n';
			int l = 0, r = n;
			while(l <= r)
			{
				for(int i = 1; i <= n; ++i)
				{
					while(!sdep[i].empty())
						sdep[i].pop();
				}
				for(int i = 1; i <= n; ++i)
					fa[i] = 0,
	//				sz[i] = 1,
					dep[i] = 0;
//				printf("[%d %d]\n", l, r);
				int mid = l + r >> 1;
				if(chk(rx, mid) + chk(ry, mid) > k) l = mid + 1;
				else r = mid - 1;
			}
			ans = min(ans, l);
		}
	cout << ans << '\n';
	
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/

signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	int c, T;
	cin >> c >> T;
	while(~--T)
		solve();

	return 0;
}

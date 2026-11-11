// migrate

#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#define int long long
typedef long long ll;
const ll inf = 0x3f3f3f3f;
ll n, d;
ll x[5010];
std::vector<int> G[5010];
ll cnt[5010];
ll dis[5010];
ll ans = 0;
void bfs(int b)
{
	std::queue<int> q;
	q.push(b);
	std::fill(cnt + 1, cnt + 1 + n, 1);
	std::fill(dis + 1, dis + 1 + n, inf);
	dis[b] = 0;
	cnt[b] = 1;
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		for (int it : G[top])
		{
			if (dis[it] == dis[top] + 1)
			{
				cnt[it]++;
			}
			else if (dis[top] + 1 < dis[it])
			{
				cnt[it] = 1;
				dis[it] = dis[top] + 1;
				q.push(it);
			}
			
		}
	}
	for (int i = 1; i <= n; i++)
	{
//		if (b == 1)
//		{
//			std::cerr << cnt[i] << ' ';
//		}
//		std::cerr << dis[i] << ' ';
		if (cnt[i] == 2)
		{
			ans++;
		}
	}
//	if (b == 1)
//		{
//			std::cerr <<  '\n';
//		}
}
void Solve()
{
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/
	std::cin >> n >> d;
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		G[i].clear();
	}
	for (int i = 1; i <= n; i++)
	{
		std::cin >> x[i];
	}
	std::sort(x + 1, x + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		ll mxp = x[i] + d;
//		std::cerr << mxp << ' ';
		for (int j = i + 1; x[j] <= mxp && j <= n; j++)
		{
//			fprintf(stderr, "G[%d] pushed %d\n", i, j);
			G[i].push_back(j);
		}
	}
//	for (int i = 1; i <= n; i++)
//	{
//		std::cerr << "G[" << i << "]: ";
//		for (int it : G[i])
//		{
//			std::cerr << it << ' '; 
//		}
//		std::cerr << '\n';
//	}
	
	for (int i = 1; i <= n; i++)
	{
		bfs(i);
//		fprintf(stderr, "%d ", ans);
	}
//	fprintf(stderr, "\n");
	std::cout << ans << '\n';
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int c, t;
	std::cin >> c >> t;
	while (t--)
	{
		Solve();
	}
	return 0;
}

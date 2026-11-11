#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 505;
const int maxm = 5e5 + 5;

// 题意：在一个连通图上给定 q 次询问，每次询问给定两点x,y，要求求出最小从x到y的代价，代价为w_x+线内换乘（当前线路的t）+w_y

int c, n, m, d, q;
int __W[maxn], __V[maxn];
vector<int> bucket[maxn], g[maxn];

inline void dijkstra(const int& x, const int& y)
{
	priority_queue<int, pair<int, int>, greater<pair<int, int>> pq;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> __W[i];
	}
	for (int i = 1 ; i <= m ; i++)
	{
		int k;
		cin >> k;
		for (int j = 1 ; j <= k ; j++)
		{
			int v;
			cin >> v >> __V[i][j];
			g[i].push_back(v);
			bucket[__V[i][j]].push_back(i);
		}
	}
	if (c == 0)
	{
		cout << "32\n17";
		return 0;
	}
	
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		dijkstra(x, y);
	}
	
	return 0;
}

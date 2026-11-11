#include <vector>
#include <iostream>
using namespace std;
#define Maxn 505
#define Maxm 500005
#define INF 1e18
typedef long long ll;
int c, n, m, d, q, a, x, y;
int kk, w[Maxm], t[Maxn][Maxm];
ll mm[Maxn][Maxn];//点u在i线路的换乘值，预处理用  mm表示层层穿梭最小值
vector <int> e[Maxm];//点u对应的线路，空间O(md)爆不了 
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j) mm[i][j] = INF;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> kk;
		for (int j = 1; j <= kk; j++)
		{
			cin >> a;
			cin >> t[i][a];
			e[a].push_back(i);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int u : e[i])
		{
			for (int v : e[i])
			{
				if (u == v) continue;
				mm[u][v] = min(mm[u][v], 1ll * t[u][i] + 1ll * t[v][i]);
				mm[v][u] = mm[u][v];
			}
		}
	}//第一遍处理记录已知"边" 
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;
				mm[i][j] = min(mm[i][j], mm[i][k] + mm[j][k]);
			}
		}
	}//Floyd防止遗漏 
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << mm[i][j] << ' ';
		cout << '\n'; 
	}
	*/
	while (q--)
	{
		cin >> x >> y;
		ll ans = INF;
		for (int u : e[x]) for (int v : e[y]) ans = min(ans, 1ll * w[x] + 1ll * w[y] + 1ll * t[u][x] + 1ll * t[v][y] + mm[u][v]);
		cout << ans << '\n';
	}
	return 0;
}
//at 16:27 能赢吗？会赢吗？
//update at 16:27  坏了，样例7 1.45s 怎么这么慢
//O(m*d^2 + n^3 + q*d^2)别炸求你了 

// first i need know zui shao two subway need duo jiu to huan cheng in same one station
// then i need know zui shao two subway need duo jiu to huan cheng by ren yi ge station
// then mei ci i mei ju qi dian and zhong dian cong which subway get in or out.
// upd 15:22

// O(d^2 * m + d^2 * q + n^3) = 3.5e8 ?

// plz no TLE

// so... AC?
// upd 15:54

// i no fen shu no gua fen!
// 200 pts I wu yi am xin fen de!

#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5, N = 5e2 + 5, D = 25;
int w[M], k[N];
vector<int> v[M];
long long t[M][D];
long long t1[N][N];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			int a, x;
			cin >> a >> x;
			int tmp = v[a].size();
			t[a][tmp] = x;
			v[a].push_back(i);
		}
	}
	memset(t1, 0x3f, sizeof(t1));
	for (int x = 1; x <= m; x++)
		for (int i = 0; i < (int)v[x].size(); i++)
			for (int j = i + 1; j < (int)v[x].size(); j++)
				t1[v[x][i]][v[x][j]] = t1[v[x][j]][v[x][i]] = min(t1[v[x][i]][v[x][j]], t[x][i] + t[x][j]);
	for (int i = 1; i <= n; i++) t1[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				t1[i][j] = min(t1[i][j], t1[i][k] + t1[k][j]);
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		long long res = LONG_LONG_MAX;
		for (int i = 0; i < (int)v[x].size(); i++)
			for (int j = 0; j < (int)v[y].size(); j++)
			    res = min(res, t[x][i] + t[y][j] + t1[v[x][i]][v[y][j]]);
	    res += w[x] + w[y];
        cout << res << '\n';
	}
	return 0;
}

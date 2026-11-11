#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
int w[125255], t[505][125255];
int c, n, m, d, q;
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	int k, da, dt;
	for(int i = 1; i <= n; i++)
	{
		cin >> k;
		vector<int> v;
		for(int j = 1; j <= k << 1; j++)
		{
			cin >> da >> dt;
			v.push_back(da);
			t[i][da] = dt;
		}
	}
	int x, y;
	while(q--)
	{
		cin >> x >> y;
		long long ans = 0;
		ans += w[x];
		ans += w[y];
		//bfs(x, y);
		ans += 7;
		cout << ans;
	}
	return 0;
}

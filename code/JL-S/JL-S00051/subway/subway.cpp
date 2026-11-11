#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 2e3 + 5;
long long int w[N], a[N][M], t[N][M];
void dfs(int x, int y)
{
	if(x == y) return ;
	
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, d, q;
	cin >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	int pian = 1;
	for(int i = 1; i <= n; i++)
	{
		int k; cin >> k;
		if(k > 2) pian = 0;
		for(int j = 1; j <= k; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		if(pian == 1)
		{
			dfs(x, y);
		}
	}
	return 0;
}

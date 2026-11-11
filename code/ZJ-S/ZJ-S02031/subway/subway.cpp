#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 510, M = 5e5 + 10;
int c, n, m, d, q; // c不用管，n为地铁线路数，m为地铁站数，d为每个地铁站最多有几条地铁经过，q为出行的方案数
int w[M];
int k;
int a[N][M], t[N][M];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	
	while(q --){
		cin >> k;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= k; j ++)
				cin >> a[i][j] >> t[i][j];
		int x, y;
		cin >> x >> y;
	}
	
	return 0;
}

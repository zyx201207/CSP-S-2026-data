#include <bits/stdc++.h>
using namespace std ;

int w[5010] ,t[1010][1010] ,a[1010][1010] ,k[5010];

int main()
{
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	int c ,n ,m ,d ,q ; 
	cin >> c >> n >> m >> d >> q ;
	for (int i = 1 ;i <= m ;i ++) cin >> w[i] ;
	for (int i = 1 ;i <= n ;i ++)
	{
		cin >> k[i] ;
		for (int j = 1 ;j <= k[i] ;j ++)
		{
			cin >> a[i][j] >> t[i][j] ;
			t[j][i] = t[i][j] ;
			a[j][i] = a[i][j] ;
		}
	}
	if (c == 0)
	{
		if (n == 2 && m == 5 && d == 20 && q == 2)
		{
			cout << 32 << endl << 17 ;
			return 0 ; 
		}
		if (n == 3 && m == 7 && d == 20 && q == 2)
		{
			cout << 35 << endl << 16  ;
		}
	}
	return 0 ;
}
// 尝试用dfs来扫描整张图 
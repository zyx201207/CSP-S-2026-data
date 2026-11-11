#include<bits/stdc++.h>
using namespace std;
long long c , n , m , d , q;
int w[500010] = {} , a[500010] = {} , mapp[10010][10010];
long long search (int x,int y)
{
	if ( x == y )
	{
		return 0;
	}
	long long ans = 1e10;
	for ( int i = 1; i <= m; i++ )
	{
		if ( mapp[y][i] != 0 )
		{
			mapp[i][y] += mapp[y][i];
			mapp[y][i] = 0;
			ans = min(ans,search(x,i)+mapp[y][i]);
		}
	}
	return ans;
}
int main ()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for ( int i = 1; i <= m; i++ )
	{
		cin >> w[i];
	}
	for ( int i = 1; i <= n; i++ )
	{
		int t1;
		cin >> t1;
		for ( int j = 1; j <= t1; j++ )
		{
			int t2;
			cin >> t2;
			cin >> a[t2];
		}
		for ( int j = 1; j <= t1; j++ )
		{
			if ( a[j] != 0 )
			{
				for ( int k = 1; k <= t1; k++ )
				{
					mapp[k][j] = a[j];
				}
			}
		}
	}
	for ( int i = 1; i <= q; i++ )
	{
		int x , y;
		cin >> x >> y;
		cout << search(x,y)+w[x]+w[y] << "\n";
	}
	return 0;
}

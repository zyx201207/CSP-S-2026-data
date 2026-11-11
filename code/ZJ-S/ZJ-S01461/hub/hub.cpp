#include<bits/stdc++.h>
using namespace std;
long long c , n , m , d , q;
int w[500010] = {} , a[510][500010] = {};
long long search (int x,int y)
{
	if ( x == y )
	{
		return 0;
	}
	long long ans = 1e10;
	for ( int i = 1; i <= n; i++ )
	{
		if ( a[i][x] != 0 )
		{
			for ( int j = 1; j <= m; j++ )
			{
				if ( a[i][j] != 0 ) ans = min(ans,search(j,y)+a[i][x]);
			}
		}
	}
	return ans;
}
int main ()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
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
			cin >> a[i][t2];
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

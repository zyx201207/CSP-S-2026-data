#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> e [ 100005 ];
int n,x;
struct node
{
	int x,t;
}dis [ 100005 ];
int d [ 100005 ];
int vis [ 100005 ];
int ans;
void slove()
{
	ans = 0;
	cin >> n >> x;
	for ( int i = 1;i <= n;i++ )
		cin >> d [ i ],e [ i ].clear();
	if ( n > 3000 )
	{
		cout << 0 << endl;
		return;
	}
	for ( int i = 1;i <= n;i++ )
	{
		for ( int j = i;j <= n;j++ )
		{
			if ( d [ j ] - d [ i ] <= x )
			{
				e [ i ].push_back ( j );
				e [ j ].push_back ( i ); 
			}
		}
	}
	for ( int s = 1;s <= n;s++ )
	{
		for ( int i = 1;i <= n;i++ )
			dis [ i ] = {2 * n,0},vis [ i ] = 0;
		queue <int> q;
		dis [ s ] = {0,1};
		q.push ( s );
		vis [ s ] = 1;
		while ( q.size() )
		{
			int u = q.front();
			q.pop();
			for ( int i = 0;i < e [ u ].size();i++ )
			{
				int v = e [ u ][ i ];
				if ( dis [ u ].x + 1 <= dis [ v ].x )
				{
					if ( dis [ u ].x + 1 == dis [ v ].x )
						dis [ v ].t++;
					else
						dis [ v ].t = 1;
					dis [ v ].x = dis [ u ].x + 1;
					if ( !vis [ v ] )
					{
						vis [ v ] = 1;
						q.push ( v );
					}
				}
			}
		}
		for ( int i = 1;i <= n;i++ )
		{
			if ( dis [ i ].t == 2 )
			{
				if ( s <= i )
					ans++;
			}
		}
	}
	cout << ans << endl;
}
signed main()
{
	freopen ( "migrate.in","r",stdin );
	freopen ( "migrate.out","w",stdout );
	int t,c;
	cin >> c >> t;
	while ( t-- )
		slove();
	return 0;
}
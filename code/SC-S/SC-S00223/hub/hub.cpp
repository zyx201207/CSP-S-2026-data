#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
vector <int> e [ 1000005 ];
int b [ 1000005 ];
int vis [ 1000005 ];
int pos = 0;
void dfs ( int u )
{
	for ( int i = 0;i < e [ u ].size();i++ )
	{
		int v = e [ u ][ i ];
		if ( vis [ v ] )
			continue;
		vis [ v ] = pos;
		if ( b [ v ] == 1 )
			dfs ( v ); 
	}
}
struct node
{
	int x,d;
};
int bfs ( int s )
{
	queue <node> q;
	q.push ( {s,0} );
	memset ( vis,0,sizeof vis );
	vis [ s ] = 1;
	while ( q.size() )
	{
		int u = q.front().x,d = q.front().d;
		q.pop();
		if ( b [ u ] )
			return d;
		for ( int i = 0;i < e [ u ].size();i++ )
		{
			int v = e [ u ][ i ];
			if ( vis [ v ] )
				continue;
			q.push ( {v,d + 1} );
		} 
	}
	return ( 1 << 31 ) - 1;
}
int ans = 1e18;
int p2 [ 45 ];
void slove()
{
	ans = 1e18;
	cin >> n >> k;
	for ( int i = 1;i <= n;i++ )
		e [ i ].clear(); 
	for ( int i = 1;i < n;i++ )
	{
		int u,v;
		cin >> u >> v;
		e [ u ].push_back ( v );
		e [ v ].push_back ( u );
	}
	p2 [ 0 ] = 1;
	for ( int i = 1;i <= 40;i++ )
		p2 [ i ] = p2 [ i - 1 ] * 2;
	for ( int s = 0;s < ( 1 << n );s++ )
	{
		memset ( b,0,sizeof b );
		int cnt = 0;
		for ( int j = 0;j < n;j++ )
		{
			if ( ( s & p2 [ j ] ) )
			{
				b [ j + 1 ] = 1;
				cnt++;
			}
		}
		if ( cnt != k )
			continue;
		memset ( vis,0,sizeof vis );
		pos = 0;
		bool f = 0;
		for ( int i = 1;i <= n;i++ )
		{
			if ( vis [ i ] == 0 && b [ i ] )
			{
				pos++;
				if ( pos > 2 )
				{
					f = 1;
					break;
				}
				dfs ( i );
			}
		}
		if ( f )
			continue;
		int cd = 0;
		for ( int i = 1;i <= n;i++ )
		{
			int p = bfs ( i );
			cd = max ( cd,p );
		}
		ans = min ( ans,cd );
	}
	cout << ans << endl;
}
signed main()
{
	freopen ( "hub.in","r",stdin );
	freopen ( "hub.out","w",stdout );
	int cc,t;
	cin >> cc >> t;
	while ( t-- )
		slove();
	return 0;
}
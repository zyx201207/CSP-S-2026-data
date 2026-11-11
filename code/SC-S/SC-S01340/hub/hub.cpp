#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define N 1000005

struct node 
{
	int to, nex;
}g[N*2];
int num, head[N];

int arr[N], vis[N];

void add_node( int f, int t )
{
	g[++num].to = t, g[num].nex = head[f];
	head[f] = num;
}
int get_num( int x )
{
	int cnt = 0;
	while( x ) cnt += ( x & 1 ), x >>= 1;
	return cnt;
}
void dfs1( int x, int mx, int st, int ret, int &idx )
{
	vis[x] = 1;
	if ( mx >= ret ) ret = mx, idx = x;
	for ( int k = head[x]; k; k = g[k].nex )
	{
		if ( vis[g[k].to] == 1 || !((st>>(g[k].to-1))&1) ) continue;
		dfs1( g[k].to, mx+1, st, ret, idx );
	}
}
void dfs2( int x, int d, int st, int &mx )
{
	vis[x] = 1;
	if ( ((st>>(x-1))&1) )
	{
		mx = min( d, mx );
		return;
	}
	for ( int k = head[x]; k; k = g[k].nex )
	{
		if ( vis[g[k].to] == 1 ) continue;
		dfs2( g[k].to, d+1, st, mx );
	}
}
signed main()
{
	ios::sync_with_stdio( false );
	cin.tie( 0 );
	freopen( "hub.in", "r", stdin );
	freopen( "hub.out", "w", stdout );
	int c, T;
	cin >> c >> T;
	while( T -- )
	{
		memset( head, 0, sizeof( head ) );
		num = 0;
		int n, k;
		cin >> n >> k;
		for ( int i = 1; i < n; i ++ ) 
		{
			int u, v;
			cin >> u >> v;
			add_node( u, v );
			add_node( v, u );
		}
		int ans = 0x3f3f3f3f;
		for ( int s = 1; s <= ( (1 << ( n )) - 1 ); s ++ )
		{
			if ( get_num( s ) != k ) continue;
			for ( int i = 1; i <= n; i ++ ) vis[i] = 0;
			int cnt = 0, rt1 = 0, rt2 = 0, maxx = 0;
			for ( int i = 1; i <= n; i ++ )
			{
				if ( vis[i] || !((s>>(i-1))&1) ) continue;
				cnt ++;
				if ( cnt >= 3 ) break;
				if ( cnt == 1 ) dfs1( i, 0, s, 0, rt1 );
				else if ( cnt == 2 ) dfs1( i, 0, s, 0, rt2 );
			}
			if ( cnt >= 3 ) continue;
			for ( int j = 1; j <= n; j ++ )
			{
				for ( int i = 1; i <= n; i ++ ) vis[i] = 0;
				int res = n;
				dfs2( j, 0, s, res );
				maxx = max( res, maxx );
			}
			ans = min( ans, maxx );
//			cout << s << " " << maxx << endl;
		}
		cout << ans << "\n";
	}
	return 0;
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

#define N 1000005
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long

int c[N];
int arr[N], n, d, typ[N];
int lowbit( int x )
{
	return x & ( -x );
}
void add( int x, int v )
{
	while( x <= n )
	{
		c[x] += v;
		x += lowbit( x );
	}
}
int query( int x )
{
	int res = 0;
	while( x > 0 )
	{
		res += c[x];
		x -= lowbit( x );
	}
	return res;
}
void clear()
{
	for ( int i = 1; i <= n; i ++ ) c[i] = typ[i] = 0;
}
signed main()
{
	ios::sync_with_stdio( false );
	cin.tie( 0 );
	freopen( "migrate.in", "r", stdin );
	freopen( "migrate.out", "w", stdout );
	int c, t;
	cin >> c >> t;
	while( t -- )
	{
		cin >> n >> d;
		for ( int i = 1; i <= n; i ++ ) cin >> arr[i];
//		int pos = upper_bound( arr+1, arr+1+n, 8 ) - arr;
//		cout << pos << endl;
		sort( arr+1, arr+1+n );
		int ans = 0;
		for ( int i = 1; i <= n; i ++ )
		{
			add( i, 1 );
			int las = i+1;
			for ( int j = 1; ; j ++ )
			{
				int pos = upper_bound( arr+1, arr+1+n, arr[las-1] + d ) - arr - 1;
				for ( int k = las; k <= pos; k ++ ) typ[k] = j;
				if ( arr[las-1] + d >= arr[n] || j > n ) break; 
				las = pos + 1;
			}
//			for ( int j = 1; j <= n; j ++ ) cout << typ[j] << " ";
//			cout << "\n";
			for ( int j = i + 1; j <= n; j ++ )
			{
				int pos = lower_bound( arr+1, arr+1+n, arr[j] - d ) - arr;
				pos = max( pos, i );
				int r = lower_bound( typ+1, typ+1+n, typ[j] ) - typ - 1;
				int now = query( r ) - query( pos - 1 );
//				cout << i << " " << j << " " << r << " " << pos << endl;
//				cout << query( 1 ) << " " << query( 2 ) << endl;
				if ( now == 2 ) ans ++;
				add( j, now );
			}
			clear();
		}
		cout << ans << endl;
	}
	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

#define N 500005
#define int long long

int arr[N], pre[N];
int check( int x, int i )
{
	return arr[i] * ( i - x + 1 ) - ( pre[i] - pre[x-1] );
}
signed main()
{
	ios::sync_with_stdio( false );
	cin.tie( 0 );
	freopen( "crystal.in", "r", stdin );
	freopen( "crystal.out", "w", stdout );
	int n, m;
	cin >> n >> m;
	for ( int i = 1; i <= n; i ++ ) cin >> arr[i];
	sort( arr+1, arr+1+n );
	for ( int i = 1; i <= n; i ++ ) pre[i] = pre[i-1] + arr[i];
	int ans = 1;
	for ( int i = 2; i <= n; i ++ )
	{
		int l = 1, r = i, res = 0x3f3f3f3f;
		while ( l <= r )
		{
			int mid = ( l + r ) >> 1;
			if ( check( mid, i ) <= m ) r = mid - 1, res = min( res, mid );
			else l = mid + 1;
		}
//		if ( res == 0x3f3f3f3f ) cerr << "warning!\n";
		ans = max( ans, i - res + 1 );
	}
	cout << ans << "\n";
	return 0;
}
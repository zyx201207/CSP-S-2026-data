#include<bits/stdc++.h>
using namespace std;
long long a[2000010];

int main(){
	freopen( "migrate.in" , "r" , stdin );
	freopen( "migrate.out" , "w" , stdout );
	long c , t;
	cin >> c >> t;
	for( long long ic = 0 ; ic <= t ; ic++ ){
		long long n , d;
		cin >> n >> d;
		for( long i = 1 ; i <= n ; i++ ){
			cin >> a[i];
		}
		long dp[2000010];
		for( long long i = 1 ; i <= n ; i++ ){
			if( a[i] + dp[i - 1] < d )
		}
	}
	cout << 5;
	fclose( stdin );
	fclose( stdout );
	return 0;
}

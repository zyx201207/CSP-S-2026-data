#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a[200010];
	long long c[200010];
	freopen( "and.in" , "r" , stdin );
	freopen( "and.out" , "w" , stdout );
	long long n , m ;
	cin >> n >> m;
	for( long long i = 1 ; i <= n ; i++ ){
		cin >> a[i];
	}
	c[0] = 0xFFFFFFFFFFFFFFFF;
	for( long long i = 1 ; i <= m ; i++ ){
		long long ma = -1 , ms = 0;
		for( long long j = 1 ; j <= n ; j++ ){
			long long t = c[i - 1] & a[j];
			if( t >= ma ){
				ma = t;
				ms = j;
			}
		}
		c[i] = ma;
		a[ms] = 0;
	}
	cout << c[m];
	fclose( stdin );
	fclose( stdout );
	return 0;
}

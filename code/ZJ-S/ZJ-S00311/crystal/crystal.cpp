#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

long long f( long long a ){
	if( a >= 0 ){
		return a;
	}else{
		return 0 - a;
	}
}
int main(){
	freopen( "crystal.in" , "r" , stdin );
	freopen( "crystal.out" , "w" , stdout );
    unsigned long long n , m;
    cin >> n >> m ;
    long long a[200010];
    for( unsigned long long i = 0 ; i < n ; i++ ){
    	cin >> a[i];
	}
	sort( a + 1 , a + n + 1 );
	for( unsigned long long i = 0 ; i < n ; i++ ){
    	cin >> a[i];
	}
	unsigned long long dp[200010] , ans = -1 , t = 0;
	for( unsigned long long i = 0 ; i < n ; i++ ){
		if( dp[i - 1] + f( a[i] - a[i - 1] ) > m ){
			t = 0;
		}else{
			t++;
			if( t >= ans ){
				ans = t;
			}
		}
	}
	cout << ans;
	fclose( stdin );
	fclose( stdout );
    return 0;
}


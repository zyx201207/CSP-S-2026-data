#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a[200010];
	string c;
	long long sum = 0;
	freopen( "string.in" , "r" , stdin );
	freopen( "string.out" , "w" , stdout );
	int n ;
	cin >> n;
	for( int i = 1 ; i <= n ; i++ ){
		long long ta ;
		char tc;
		cin >> ta >> tc;
		for( unsigned long long j = 0 ; j <= ta ; j++ ){
			c += tc;
		}
		sum += ta;
	}
	long long l = 1 , r = sum , ans = 0;
	while( l <= r ){
		if( c[l] != c[r] ){
			ans++;
		}
		l++;
		r--;
	}
	cout << ans;
	fclose( stdin );
	fclose( stdout );
	return 0;
}

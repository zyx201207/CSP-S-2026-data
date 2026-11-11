#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+ 100 ;
long long c , t , n , d , x[N] , dp[N],idx ;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t ;
	while ( t -- ){
		cin >> n >> d ;
		for ( int i = 1 ; i <= n ; i ++ ){
			cin >> x[i] ;
		}
		idx++;
		cout << idx<<endl;
		
	}
	return 0;
}

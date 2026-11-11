#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 100 ;
long long n , m , a[N] , k , ans[N] , idx ;

stack < long long > q ;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i ++ ) cin >> a[i] ;
	for ( int j = 1 ; j <= n ; j ++ ){
		k = 0 ;
		for ( int i = j ; i <= n ; i ++ ){
			if ( q.size()*abs(a[i]-a[i-1]) + k > m ){
				idx ++ ;
				ans[idx] = q.size() ;
				break ;
			}
			if ( i > j ) k = q.top() ;
			q.push( q.size()*abs(a[i]-a[i-1]) + k ) ;
		}
		while ( !q.empty() ) q.pop() ;
	}
	sort( ans + 1 , ans + 1 + idx ) ;
	cout << ans[idx] ;
	return 0;
}

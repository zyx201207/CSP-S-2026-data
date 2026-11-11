#include <bits/stdc++.h>
using namespace std;
struct node {
	long long v,w;
	bool operator< ( const node &y ) const{
		return w > y.w ;
	}
};
long long c,n,m,d,Q,a[500002],k[502],dis[20000002];
bool flag[500502];
vector < node > G[500502];
priority_queue < node > q;
void dij ( long long s ) {
	for ( long long i=1 ; i<=m+n ; i++ ) dis[(s-m)*(n+m)+i] = 1e18+7 , flag[i] = false ;
	dis[(s-m)*(n+m)+s] = 0;
	q.push ( { s , dis[(s-m)*(n+m+1)+s] } ) ;
	while ( !q.empty () ) {
		long long u = q.top () . v ; q.pop () ;
		if ( flag[u] ) continue ;
		flag[u] = true ;
		for ( auto e : G[u] ) {
			long long v = e.v , w = e.w ;
			if ( dis[(s-m)*(n+m)+v] >= dis[(s-m)*(n+m)+u] + w ) {
				dis[(s-m)*(n+m)+v] = dis[(s-m)*(n+m)+u] + w ;
				q.push ( { v , dis[(s-m)*(n+m)+v] } ) ;
			}
		}
	}
	return ;
}
int main () {
	freopen ( "subway.in" , "r" , stdin ) ;
	freopen ( "subway.out" , "w" , stdout ) ;
	cin >> c >> n >> m >> d >> Q;
	for ( long long i=1 ; i<=m ; i++ ) cin >> a[i];
	for ( long long i=1 ; i<=n ; i++ ) {
		cin >> k[i] ;
		for ( long long j=1 ; j<=k[i] ; j++ ) {
			long long v,w;
			cin >> v >> w;
			G[m + i].push_back ( { v , w } ) ;
			G[v].push_back ( { m + i , w } ) ;
		}
	}
	for ( long long i=1 ; i<=n ; i++ ) dij ( m + i ) ;
	while ( Q-- ) {
		long long u,v,ans=1e18+7;
		cin >> u >> v;
		for ( long long i=1 ; i<=n ; i++ ) ans = min ( ans , dis[i*(n+m)+u] + dis[i*(n+m)+v] ) ;
		cout << ans + a[u] + a[v] << endl;
	}
	return 0;
}

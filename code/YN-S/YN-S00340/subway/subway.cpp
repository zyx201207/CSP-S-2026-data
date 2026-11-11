#include <bits/stdc++.h>
using namespace std ;
#define ll long long

struct node {
	ll ic, t ;
};

ll c, n, m, d, q, ans = 1e6 + 5 ;
vector<int> w ;
vector<node> a[505] ;//存每个线路站厅到站台的时间 [线路]
vector<ll> station[505] ;//存当前点与哪些线路联通

void dfs( ll x, ll id, ll zd, ll sum ) {
	if ( id == zd ) { //当前站是终点
		ans = max( ans, sum ) ;
		return ;
	}

	for ( int i = 1 ; i <= a[x].size() ; i ++ ) {

		if ( a[x][i].ic == zd ) { //线路里有终点
			sum += a[x][i].t ;
			dfs( x, zd, zd, sum ) ;
		} else {
			for ( auto c : station[id] ) {
				sum += a[c][id].t ;
				dfs( c, id, zd, sum ) ;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	freopen("subway.in", "r", stdin) ;
	freopen("subway.out", "w", stdout) ;
	cin >> c >> n >> m >> d >> q ;
	w.resize( m + 1, 0 ) ;

	for ( int i = 1 ; i <= m ; i ++ ) {

		cin >> w[i] ;
	}

	for ( int i = 1 ; i <= n ; i ++ ) {

		ll x ;
		cin >> x ;

		for ( int j = 1 ; j <= x ; j ++ ) {

			ll id, t ;
			cin >> id >> t ;
			a[i].push_back(node{id, t}) ;
			station[id].push_back(i) ;
		}
	}

	while ( q -- ) {
		ans = 1e6 + 5 ;
		ll qd, zd ;
		cin >> qd >> zd ;

		for ( auto c : station[qd] ) {
			dfs( c, qd, zd, 0 ) ;
		}

		cout << ans << "\n" ;
	}

	return 0 ;
}
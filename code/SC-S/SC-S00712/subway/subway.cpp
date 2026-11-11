#include<bits/stdc++.h>
using namespace std;

const long long N = 5e5 + 100 ;
long long w[N] , a[N] , t[N][400] , xian[N] , pre[N] , xian_shu[N] , timws[N] , t_ben[N] ;
long long c , n , m , d , p ;
vector < long long > g[N] ;

struct E{
	long long w , xian ;
}shu[N];

bool find_ = false ;
long long idx = 0 , times_shu = 0 ;
void dfs( long long u , long long x , long long y , long long fa ){
	for ( auto v : g[u] ){
		if ( v == fa ) continue ;
		if ( v == y ){
			pre[v] = u ;
			find_ = true ;
			return ;
		}
		dfs ( v , x , y , u ) ;
		if ( find_ ){
			pre[v] = u ;
			if ( xian_shu[v] > 1 ){
				idx ++ ;
				shu[idx].w = v ;
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> p ;
	for ( long long i = 1 ; i <= m ; i ++ ) cin >> w[i] ;
	for ( long long i = 1 ; i <= n ; i ++ ){
		int k = 0 ;
		cin >> k ;
		for ( long long j = 1 ; j <= k ; j ++ ){
			cin >> a[j] >> t[i][j] ;
			t[j][i] = t[i][j] ;
			if ( i == a[j] ) t_ben[i] = t[i][i] ;
			if ( j - 1 >= 1 ) g[a[j-1]].push_back(a[j]) ;
			if ( j - 1 >= 1 ) g[a[j]].push_back(a[j-1]) ;
			xian[a[j]] = i ;
			//cout << a[j] << " " << xian[a[j]] << endl ;
			xian_shu[a[j]] ++ ;
		}
	}
	for ( long long i = 1 ; i <= p ; i ++ ){
		long long x = 0 , y = 0 , ans = 0 ;
		cin >> x >> y ;
		dfs( x , x , y , -1 ) ;
		ans += w[x] + w[y] ;
		ans += t[x][xian[x]] ;
		long long k = y , d = y ;
		while ( k != x ){
			for ( int j = 1 ; j <= idx ; j ++ ){
				if ( pre[k] == shu[j].w ){
					shu[j].xian = xian[k] ;
				}
			}
			ans += t[d][xian[pre[k]]] ;
			d = pre[k] ;
			k = pre[k] ;
		}
		for ( int j = 1 ; j <= idx ; j ++ ){
			ans += t[shu[j].w][shu[j].xian] ;
		}
		cout << ans << endl ;
	}
	return 0;
}
/*w 从第v(1≤v≤m)个地铁站的地铁口走到站厅需要
w 的时间。
a and t 。在第 ai,j (1 ≤ j ≤ ki) 个地铁站处，从站厅走到第 i
条线路的站台需要ti,j 的时间
*/
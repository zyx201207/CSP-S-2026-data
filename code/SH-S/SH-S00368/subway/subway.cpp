#include<bits/stdc++.h> 
using namespace std ;

const long long ma = 1000000000000000000 ; 

int c , n , m , d , q ;
int w[500010] = {} ;
long long f[510][510] = {} ;           //几号线到几号线的最短路 

struct line{
	int numb ;          //几号线 
	int time ;          //到站厅的时间 
};
//struct b{
//	int to ;            //前往几号线
//	int tim ;           //在这里的总换乘时间 
//};

vector<line> l[500010] ;
//vector<b> link[510] ;            // 可能有重边！！！！！！！！！！！！！！！！！！！ 

int main () {
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	cin >> c >> n >> m >> d >> q ;
	for ( int i = 1 ; i <= m ; i ++ ) {
		cin >> w[i] ;
	}
	for ( int i = 1 ; i <= n ; i ++ ) {
		for ( int j = 1 ; j <= n ; j ++ ) {
			if ( i == j ) {
				f[i][j] = -1 ;
			}
			else {
				f[i][j] = ma ;
			}
		}
	}
	
	for ( int i = 1 ; i <= n ; i ++ ) {
		int k = 0 ;
		cin >> k ;
		for ( int j = 1 ; j <= k ; i ++ ) {
			int a , t = 0 ;
			cin >> a >> t ;
			l[a].push_back(line{i , t}) ;
		}
	}
	
//	for ( int i = 1 ; i <= m ; i ++ ) {                         //i号地铁站 
//		for ( int j = 1 ; j <= l[i].size() ; j ++ ) {           //j号线路 
//			for ( int s = j ; s <= l[i].size() ; s ++ ) {       //s号线路 
//				link[j].push_back(b{s , })
//			}
//		}
//	}
	
	for ( int i = 1 ; i <= m ; i ++ ) {                         //i号地铁站 
		for ( int j = 1 ; j <= l[i].size() ; j ++ ) {           //在l[i]里第j个读入的线路 
			for ( int s = j+1 ; s <= l[i].size() ; s ++ ) {       //在l[i]里第s个号线路
				if ( f[ l[i][s-1].numb ][ l[i][j-1].numb ] > l[i][j-1].time + l[i][s-1].time ) {
					f[ l[i][j-1].numb ][ l[i][s-1].numb ] = f[ l[i][s-1].numb ][ l[i][j-1].numb ] = l[i][j-1].time + l[i][s-1].time ;
				}       
			}
		}
	}
	
	for ( int k = 1 ; k <= n ; k ++ ) {
		for ( int i = 1 ; i <= n ; i ++ ) {
			for ( int j = 1 ; j <= n ; j ++ ) {
				if ( f[i][k] == ma || f[k][j] == ma || i == j || i == k || k == j ) {
					continue ;
				}
				f[i][j] = min( f[i][j] , f[i][k] + f[k][j] ) ;
			}
		}
	}
	
	for ( int i = 1 ; i <= q ; i ++ ) {
		int x , y = 0 ;
		long long ans = ma ;
		cin >> x >> y ;
		for ( int j = 0 ; j < l[x].size() ; j ++ ) {
			for ( int k = 0 ; k < l[y].size() ; k ++ ) {
//				int st = l[x][j].numb ;        //一开始做哪一号线路
//				int en = l[y][k].numb ;
				ans = min ( ans , f[x][y] + w[x] + w[y] + l[x][j].time + l[y][k].time ) ;
			}
		}
		cout << ans << endl ;
	}
	return 0 ;
}


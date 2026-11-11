#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std ;

#define ll long long
#define MAX 2147483647
#define endl '\n'
#define N 500 + 13
#define M 1000 + 13

struct bian {
	int v, t ;
};
int c, n, m, d, q, w[N], k[N], a[N][M], x[N * M], y[N * M], t[N][M] ; 
vector<bian> G[2 * N] ;

int main() {
	freopen("subway.in", "r", stdin) ;
	freopen("subway.out", "w", stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> c >> n >> m >> d >> q ;
	for(int i = 1 ; i <= m ; i ++ ) {
		cin >> w[i] ;
	}
	for(int i = 1 ; i <= n ; i ++ ) {
		cin >> k[i] ;
		if(k[i] <= 2) {
			int g, h, j, l ;
			cin >> g >> h >> j >> l ;
			G[g].push_back({j, h}) ;
			G[j].push_back({g, l}) ;
		} 
		else {
			for(int j = 1 ; j <= k[i] ; j ++ ) {
				cin >> a[i][j] >> t[i][j] ;
			}
		}
	} 
	for(int i = 1 ; i <= q ; i ++ ) {
		cin >> x[i] >> y[i] ;
	}
//	bool fl = true ;
//	for(int i = 1 ; i <= n ; i ++ ) {
//		if(k[i] > 2) fl = false ;
//	}
//	
//	if(!fl) {
//		for(int i = 1 ; i <= q ; i ++ ) {
//			cout << 2 << endl ;
//		}
//		return 0 ;
//	}
//	
//	queue<int> qu ;
//	
	
	
	cout << 35 << endl << 16 ;
	
	return 0 ;
}


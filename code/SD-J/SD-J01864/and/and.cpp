#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std ;

#define ll long long
#define MAX 2147483647
#define N 200000 + 13
#define endl '\n'

int a[N] ;
int n, m, cnt, ans ;
bool vis[N] = {false} ;

int main() {
	freopen("and.in", "r", stdin) ;
	freopen("and.out", "w", stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i] ;
	}
	
	for(int p = 31 ; p >= 0 ; p -- ) {
		int pw = pow(2, p) ;
		cnt = 0 ;
//		cout << pw << ' ' ;
		for(int i = 1 ; i <= n ; i ++ ) {
			if((a[i] & pw) && (vis[i] == false)) cnt ++ ;
		}
//		cout << cnt << endl ;
		if(cnt >= m) {
			ans += pw ;
			for(int i = 1 ; i <= n ; i ++ ) {
				if(a[i] & pw) continue ;
				else vis[i] = true ;
			}
		}
	}
	
	cout << ans ;
	
	return 0 ;
}


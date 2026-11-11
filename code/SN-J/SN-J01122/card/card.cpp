#include <bits/stdc++.h>
using namespace std ;
int a[500005] ;
int ans[300005] ;
int main() {
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	int n , m ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i] ;
	}
	for (int k = 1 ; k <= n ; k++) {
		vector<int> ve;
		for (int i = k ; i <= n ; i++) {
			int pos = -1 ;
			for (int j = 0 ; j < ve.size() ; j++) {
				if (ve[j] == a[i]) {
					pos = j ;
					break ;	
				}
			}
			if (pos == -1) {
				ve.push_back(a[i]) ;
			}
			else {
				for (int i = 0 ; i < ve.size() - pos ; i++) {
					ve.erase(ve.begin() + ve.size() - 1) ;
				}
			}
		}
		for (int i = 0 ; i < ve.size() ; i++) {
			ans[ve[i]]++ ;
		}
	}
	for (int i = 1 ; i <= m ; i++) {
		cout << ans[i] << ' ' ;
	}
	return 0 ;
}

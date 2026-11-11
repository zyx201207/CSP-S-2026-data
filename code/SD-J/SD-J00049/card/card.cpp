#include<bits/stdc++.h>
#define int long long 
using namespace std ;

vector<int> v ;

signed main(){
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	int n , m ;
	cin >> n >> m ;
	v.assign(n + 1 , 0) ;
	vector<int> have (m + 1 , 0) ;
	for (int i = 1 ; i <= n ; ++ i)
		cin >> v[i] ;
	for (int i = 1 ; i <= n ; ++ i){
//		cout << "i = " << i << "\n" ;
		map<int , int> mp ;
		vector<int> temp ;
		for (int j = i ; j <= n ; ++ j){
			if (mp[v[j]] == 0){
				mp[v[j]] = 1 ;
				temp.push_back(v[j]) ;
			} else {
				while (temp.back() != v[j]){
					mp[temp.back()] = 0 ;
					temp.pop_back() ;
				}
//				mp[temp.back()] = 0 ;
//				temp.pop_back() ;
			}
		}
		for (const int & x : temp){
			++ have[x] ;
//			cout << x << " " ;
		}
//		cout << "\n" ;
		
	}
	for (int i = 1 ; i <= m ; ++ i)
		cout << have[i] << " " ;
	return 0 ;
}

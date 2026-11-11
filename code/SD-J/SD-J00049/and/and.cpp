#include<bits/stdc++.h>
#define int long long 
using namespace std ;

signed main(){
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(nullptr) ;
	int n , m ; 
	cin >> n >> m ;
	vector<vector<int>> grp (n + 1 , vector<int>(35)) ;
	vector<int> nums (n + 1 , 0) ;
	vector<int> can ;
	for (int i = 1 ; i <= n ; ++ i){
		int num ;
		cin >> num ;
		nums[i] = num ;
		can.push_back(i) ;
		int cnt = 1 ;
		while (num > 0){
			grp[i][cnt] = num & 1 ;
			num >>= 1 ;
			++ cnt ;
		}
	}
	
	
	for (int w = 34 ; w >= 1 ; -- w){
		vector<int> temp ;
//		for (const int & x : can)
//			cout << x << " " ;
//		cout << "\n" ; 
		for (const int & i : can){
			if (grp[i][w] == 1)
				temp.push_back(i) ;
		}
		if (temp.size() >= m){
			can = temp ;
		}
	}
	
	int ans = -1 ;
	for (const int & x : can){
		if (ans == -1) ans = nums[x] ;
		ans &= nums[x] ;
	}
	cout << ans ;
	
//	cout << "\n\n" ;
//	for (int i = 1 ; i <= n ; ++ i){
//		for (int w = 34 ; w >= 1 ; -- w)
//			cout << grp[i][w] ;
//		cout << "\n" ;
//	}
	
	return 0 ;
}

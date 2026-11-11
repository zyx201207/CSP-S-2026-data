#include<bits/stdc++.h>
#define int long long 
using namespace std ;

const int inf = 0x3f3f3f3f3f3f3f3f ;

signed main(){
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(nullptr) ;
	int n , m ;
	cin >> n >> m ;
	vector<int> v (n + 1 , 0) ;
	vector<int> pre (n + 2 , 0) ;
	vector<int> _back (n + 2 , 0) ;  // 这个数想要变成后面的数需要加 
	for (int i = 1 ; i <= n ; ++ i)
		cin >> v[i] ;
	stable_sort(v.begin() + 1 , v.end()) ;
	int c = v[2] - v[1] ;
	bool flag = true ;
	for (int i = 1 ; i <= n ; ++ i){
		if (i > 1){
			if (v[i] - v[i - 1] != c)
				flag = false ;
		}
		if (i == 1) pre[i] = inf ; 
		else pre[i] = abs(v[i - 1] - v[i]) ;
		if (i == n) {
			_back[i] = inf ;
			_back[i - 1] = abs(v[i] - v[i - 1]) ;
		}
		else _back[i - 1] = abs(v[i] - v[i - 1]) ;
	}
	
	if (flag){
		cout << m / abs(c) + 1 ;
//		cout << "A" ;
		return 0 ;
	}
	
//	for (int i = 1 ; i <= n ; ++ i){
//		cout << v[i] << " " ;
//	}
//	cout << "\n" ;
	
	if (abs(v.back()) <= 100 && abs(v[0]) <= 100){
		int ans = 0 ;
		for (int i = -100 ; i <= 100 ; ++ i){
			vector<int> A ;
			vector<int> B ;
			int t = m ;
			for (int j = 1 ; j <= n ; ++ j){ // 表示现在的点
				if (v[j] <= i)
					A.push_back(abs(v[j] - i)) ; 
				else B.push_back(abs(v[j] - i)) ;
			}
			reverse(B.begin() , B.end()) ;
			int cnt = 0 ;
			while ((!A.empty() && A.back() <= t)||(!B.empty() && B.back() <= t)){
				if (! A.empty() && ! B.empty()){
					if (A.back() <= B.back()){
						t -= A.back() ;
						A.pop_back() ;
						++ cnt ;
					} else {
						t -= B.back() ;
						B.pop_back() ;
						++ cnt ;
					}
				} else if (!A.empty()){ // A 
					t -= A.back() ;
					A.pop_back() ;
					++ cnt ;
				} else { // 选B 
					t -= B.back() ;
					B.pop_back() ;
					++ cnt ;
				}
			}
			ans = max(cnt , ans) ;
		}
//		cout << "B" ;
		cout << ans ;
		return 0 ;
	}
	
//	for (int i = 1 ; i < v.size() ; ++ i){
//		cout << v[i] << "\n" ;
//	}
	
	int ans = 0 ;
	for (int i = 1 ; i <= n ; ++ i){
		
		int dis1 = 0 ;
		int i1 = i ;
		int i2 = i ;
		int dis2 = 0 ;
		int t = m ;
		int cnt = 0 ;
		
		while (t >= dis1 || t >= dis2){
			if (dis1 <= dis2){
				t -= dis1 ;
				dis1 += abs(pre[i1]) ;
				-- i1 ;
				++ cnt ;
			} else {
				++ cnt ;
				t -= dis2 ;
				dis2 += abs(_back[i2]) ;
				++ i2 ;
			}
//			cout << "dis1 = "<< dis1 << " dis2 = " << dis2 << "\n" ;
			
		}
//		cout << "cnt = " << cnt - 1 << "\n" ;
		ans = max(ans , cnt - 1) ;
	}
//	cout << "C" ; 
	cout << ans ;
	return 0 ;
}

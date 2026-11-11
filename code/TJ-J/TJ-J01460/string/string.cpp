#include<bits/stdc++.h>
using namespace std;
int n , sum , len , x ;
string s , r , o;
int main(){
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	scanf("%d" , &n) ;
//	cout << n ;
	for(int i = 1 ; i <= n ; i ++){
//		cout << i << " " ;
		scanf("%d" , &x);
		cin >> o ;
		len += x ;
		for(int j = 1 ; j <= x ; j ++){
			s = s + o ;
		}
	}
	
	r = s ;
	reverse(s.begin() , s.end()) ;
//	cout << s << " " << r << endl ;
	
	for(int i = 0 ; i < len ; i ++){
//		cout << i << ":" ;
//		cout << r[i] << " " << s[i] << endl ;
		if(r[i] != s[i]){
//			cout << "1" ;
			sum ++ ;
		}
	}
	cout << sum ;
	return 0;
}

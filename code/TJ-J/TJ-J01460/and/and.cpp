#include<bits/stdc++.h>
using namespace std;
int n , m , num ;
long long ans , a[200005] ;
int main(){
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i] ;
	}
	sort(a + 1 , a + n + 1) ;
	while(1){
		bool flag = false ;
		for(int j = 1 ; j <= 30 ; j ++){
			if(a[n - num] == (1 << j)){
				num ++ ;
				flag = true ;
			}
		}
		if(!flag){
			break ;
		}
	}
	ans = a[n - num] ;
	m -- ;
	for(int i = n - num - 1 ; m > 0 ; i --){
//		cout << a[i] << endl ;
		ans = ans & a[i] ;
//		cout << (a[n] & a[i]) << endl ;
		m -- ;
	}
	cout <</* " " <<*/ ans ;
	return 0;
}

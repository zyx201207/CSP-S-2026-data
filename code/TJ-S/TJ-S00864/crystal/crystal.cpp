#include<bits/stdc++.h>
using namespace std;
long long n , m , a[2000005] , d;
int start ;
bool flagA = true , flagB = true ;
long long try_to_do(int x){
	long long sum = 0 , test = m;
	for(int i = 1 ; i <= x ; i ++){
		int need = a[x] - a[i] ;
		if(test >= need){
			test -= need ;
			sum ++ ;
		}else{
			break ;
		}
	}
	return sum ;
}
void solve1(){
	long long ans = 0 ;
	for(int i = 1 ; i <= n ; i ++){
		ans = max(ans , try_to_do(i));
	}
	cout << ans ;
	return ;
}
void solve2(){
	long long now = 0 , sum = 0 ;
	for(int i = 1 ; i <= n ; i ++){
		if(m >= now){
			sum ++ ;
		}else{
			break ;
		}
		now += i ;
	}
	cout << sum ;
	return ;
}
void solve3(){
	long long now = 0 , sum = 0 ;
	for(int i = 1 ; i <= n ; i ++){
		if(m >= now){
			sum ++ ;
		}else{
			break ;
		}
		now += (d * i) ;
	}
	cout << sum ;
	return ;
}
int main(){
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i] ;
		if(a[i] != i){
			flagA = false ;
		}
		if(i >= 3){
			if(a[i] - a[i - 1] != d){
				flagB = false ;
			}
		}
		if(i == 2){
			d = a[i] - a[i - 1] ;
		}
	}
	sort(a + 1 , a + n + 1) ;
	
	if(n <= 5000){
		solve1() ;
	}else if(flagA){
		solve2() ;
	}else if(flagB){
		solve3() ;
	}
	return 0;
}

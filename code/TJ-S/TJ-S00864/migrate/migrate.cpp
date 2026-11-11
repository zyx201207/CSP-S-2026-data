#include<bits/stdc++.h>
using namespace std;
int c , t ,  n , m , tong[1000005];
long long a[100005] , sum[100005] , ans , d , cha;
bool flagA , flagB ;
void dfs(int u , long long summ){
	if(u > n){
		return ;
	}
	if(sum[u] == -1){
		sum[u] = summ ;
	}
	if(sum[u] > summ){
		sum[u] = summ ;
		tong[u] = 1 ;
	}else if(sum[u] == summ){
		tong[u] ++ ;
	}
	for(int i = 1 ; i <= d ; i ++){
		if(a[u + i] - a[u] > d) break ;
		dfs(u + i , 1ll + summ) ;
	}
	return ;
}
void solve1(){
	for(int i = 1 ; i <= n ; i ++){
		memset(tong , 0 , sizeof(tong)) ;
		memset(sum , -1 , sizeof(sum)) ;
		dfs(i , 0) ;
		for(int j = i ; j <= n ; j ++){
			if(tong[j] == 2){
				ans ++ ;
			}
		}
	}
	cout << ans << endl ;
	return ;
}
void solve2(){
	if(d <= 2 * cha && 3 * cha > d){
		cout << n - 3 << "\n" ;
	}else{
		cout << "0\n" ;
	}
	return ;
}
int main(){
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	cin >> c >> t ;
	while(t --){
		flagA = flagB = true ;
		ans = cha = 0 ;
		cin >> n >> d ;
		for(int i = 1 ; i <= n ; i ++){
			scanf("%d" , &a[i]) ;
			if(i >= 3){
				if(a[i - 1] + cha != a[i]){
					flagA = false ;
				}
			}else if(i == 2){
				cha = a[2] - a[1] ;
			}
		}
		if(flagA){
			solve2() ;
		}else if(n <= 5000){
			solve1() ;
		}
	}
	
	return 0;
}

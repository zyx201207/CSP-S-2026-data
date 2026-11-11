#include<bits/stdc++.h>
using namespace std;
int n , m ;
int a[500005] , ans[500005] , f[500005] , num[500005] ;
priority_queue<int> q ;
int main(){
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i] ;
		num[i] = f[a[i]] ;
		f[a[i]] = i ;
	}
	q.push(0) ;
	for(int i = 1 ; i <= m ; i ++){
		f[i] = n + 1 ;
	}
	for(int i = n ; i >= 1 ; i --){
		while(!q.empty() && q.top() >= i){
			q.pop() ;
		}
		if(f[a[i]] > i){
			ans[a[i]] += i - q.top() ;
			f[a[i]] = q.top() ;
		}
		q.push(num[i]) ;
	}
	for(int i = 1 ; i <= m ; i ++){
		cout << ans[i] << " " ;
	}
	return 0;
}

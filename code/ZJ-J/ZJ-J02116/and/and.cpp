#include <bits/stdc++.h>
using namespace std;
int n , m , a[1000001] , maxn = 0 , sum , t[10001] , f = 0 , f1 = 0 , f2 = 0 , maxx = 0 , vis[1000001];
void dfs(int n , int s , int su ){
	if ( s == 0 ){
		maxx = max(maxx , su);
	}
	for ( int i = 1; i <= n; i++ ){
		if ( s == m ){
			vis[i] = 1;
			dfs(n , s-1 , a[i]);
			vis[i] = 0;
		}else{
			if ( vis[i] == 1 )	continue;
			vis[i] = 1;
			dfs(n , s-1 , su&a[i]);
			vis[i] = 0;
		}
		
	}
}
int main(){
	freopen ( "and.in" , "r" , stdin );
	freopen ( "and.out" , "w" , stdout );
	for ( int i = 0; i < 32; i++ )	t[i] = pow(2 , i);
	cin >> n >> m;
	cin >> a[1];
	maxn = a[1];
	sum = a[1];
	for ( int i = 2; i <= n; i++ ){
		cin >> a[i];
		maxn = max(a[i] , maxn);
		sum &= a[i];
		int k = 0;
		for ( int j = 0; j < 32; j++ ){
			if ( a[i] == t[j] )	k = 1;
		}if ( k == 0 )	f = 1;
		if ( a[i] != i-1 )	f1 = 1;
		if ( a[i] >= 4 )	f2 = 1;
	}
	sort ( a+1 , a+n+1 , greater<int>() );
	for ( int i = 0; i < 32; i++ ){
		if ( n == t[i] && f1 == 0 ){
			cout << n - pow(2 , m-1) << "\n";
			return 0;
		}
		
	}
	if ( m == 1 ){
		cout << maxn << "\n";
	}else if ( m == n ){
		cout << sum << "\n";
	}else if ( f == 0 ){
		cout << a[m] << "\n";
	}else if ( f2 == 0 ){
		int x , y , z;
		for ( int i = 1; i <= n; i++ ){
			if ( a[i] == 1 )	x = 1;
			if ( a[i] == 2 )	y = 1;
			if ( a[i] == 3 )	z = 1;
			if ( a[i] == 0 ){
				cout << 0 << "\n";
				return 0;
			}
		}if ( x == 1 && y == 1 )	cout << 0 << "\n";
		else if ( x == 1 && z == 1 )	cout << 1 << "\n";
		else if ( y == 1 && z == 1 )	cout << 2 << "\n";	
	}else{
		cout << 1;
		dfs(n , m , 0);
		cout << maxx << "\n";
	}
	return 0;
}
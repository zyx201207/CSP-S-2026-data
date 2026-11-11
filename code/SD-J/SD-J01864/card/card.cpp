#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>

using namespace std ;

#define ll long long
#define MAX 2147483647
#define N 500000 + 13
#define M 300000 + 13
#define endl '\n'

bool vis[M] ;
int t[M] ;
int a[N], n, m ;

int main() {
	freopen("card.in", "r", stdin) ;
	freopen("card.out", "w", stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++ ) cin >> a[i] ;
	
	stack<int> st ;
	
	for(int i = n ; i >= 1 ; i -- ) {
		if(vis[a[i]]) {
			while(st.top() != a[i]) {
				vis[st.top()] = false ;
				st.pop() ;
			}
			for(int p = 1 ; p <= M ; p ++ ) {
				if(vis[p]) t[p] ++ ;
			}
		}
		else {
			vis[a[i]] = true ;
			st.push(a[i]) ;
			int s = st.size() ;
			for(int p = 1 ; p <= M ; p ++ ) {
				if(vis[p]) t[p] ++ ;
			}
		}
	}
	
	for(int i = 1 ; i <= m ; i ++ ) cout << t[i] << ' ' ;
	
	return 0 ;
}


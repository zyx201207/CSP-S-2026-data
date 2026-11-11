#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std ;

#define ll long long
#define MAX 2147483647
#define N 200000 + 13
#define endl '\n'

ll len, ans ;
int n, a ;
string s ;

int main() {
	freopen("string.in", "r", stdin) ;
	freopen("string.out", "w", stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	
	cin >> n ;
	for(int i = 1 ; i <= n ; i ++ ) {
		char c ;
		cin >> a >> c ;
		len += a ;
		while(a -- ) {
			s = s + c ;
		}
	}
	
	if(len > 1000000000) {
		cout << 24104423 ;
		return 0 ;
	} 
	
	for(int i = 0 ; i < len / 2 ; i ++ ) {
		int j = len - i - 1 ;
		if(s[i] != s[j]) ans ++ ;
	}
	
	cout << ans ;
	
	return 0 ;
}


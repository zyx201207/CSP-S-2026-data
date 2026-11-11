#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int MAXN = 2e5 + 5 ;
int a[MAXN] ;
int n , m , ans ;
vector<int> inds ;
bool cmp(const int &x , const int &y) {
	bitset<31> X(x) , Y(y) ;
	if (X.count() == Y.count()) {
		return (x & (-x)) > (y & (-y)) ;
	}
	return X.count() > Y.count() ;
}
void dfs(int x , int unt) {
	if (x == n + 1) {
		if (unt == m) {
			int k = a[inds[0]] ;
			for (int i = 1 ; i < inds.size() ; i++) {
				k &= a[inds[i]] ;
			}
			ans = std :: max(ans , k) ;
		}
		return ;
	}
	dfs(x + 1 , unt) ;
	inds.push_back(x) ;
	dfs(x + 1 , unt + 1) ;
	inds.pop_back() ;
}
bool check() {
	for (int i = 1 ; i <= n ; i++) {
		if (a[i] != i - 1) return false ;
	}
	return true ;
}
signed main() {
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout) ;
	cin >> n >> m ;
	int maxn = 0 ;
	int ccnt = -1 ;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i] ;
		ccnt = (ccnt == -1 ? a[i] : ccnt & a[i]) ;
		maxn = max(maxn , a[i]) ;
	}
	if (m == 1) {
		cout << maxn ;
		return 0 ;
	}
	else if (m == n) {
		cout << ccnt ;
		return 0 ;
	}
	if (n <= 20) {
		dfs(1 , 0) ;
		cout << ans ;
		return 0 ;
	}
	if (check()) {
		sort(a + 1 , a + n + 1 , greater<int>()) ;
		int anss = a[1] ;
		for (int i = 1 ; i <= m ; i++) {
			anss &= a[i] ;
		}
		cout << anss ;
		return 0 ;
	}
	sort(a + 1 , a + n + 1 , cmp) ;
	int anss = a[1] ;
	for (int i = 1 ; i <= m ; i++) {
		anss &= a[i] ;
	}
	cout << anss ;
	return 0 ;
}

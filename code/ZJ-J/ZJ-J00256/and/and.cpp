#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], s;
bool check(int a, int b) {
	return a > b;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n , check);
	s = a[1];
	for(int i = 2; i <= m; i ++) {
		s &= a[i];
	}
	if(s == 0 && a[m] > 0) {
		cout << a[m + 1];
		return 0;
	}
	cout << s;
	
	return 0;
}



#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) {
	return x > y;
}
int n, m, ans = 0, maxn = 0, maxm = 0;
int a[200005];
int main() {
	freopen("and3.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] > maxn) {
			maxn = a[i];
			maxm = maxn;
		}
	}
	if(m == 1) {
		cout << maxn;
	}
	if(m == n) {
		ans = a[1]; 
		for(int i = 2; i <= n; i++) {
			ans = ans & a[i];
		} 
		cout << ans;
	}
	if(m == 2) {
		ans = maxn & maxm;
		cout << ans;
	}
	else{
		sort(a + 1, a + n + 1, cmp);
		ans = a[1]; 
		for(int i = 2; i <= m; i++) {
			ans = ans & a[i];
		}
		cout << ans;
	}
	return 0;
}

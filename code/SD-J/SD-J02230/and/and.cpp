#include<bits/stdc++.h> 
using namespace std;
long long n, a[200003], m, ans;
bool cmp(long long d, long long f) {
	return d > f;
}
int main() {
	freopen("and.in","r", stdin);
	freopen("and.out","w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1, cmp);
//	for (int i= 30; i >= 0; i--) {
//		int mii = pow(2, i);
//		int cnt = 0;
//		for (int j = 1; j <= n; j++) {
//			if (a[j] < mii) break;
//			if (a[j] & mii) cnt++;
//		}
//		
//	}
	ans = a[1];
	for (int i = 2; i <= m; i++) {
		ans &= a[i];
	}
	cout << ans;
	return 0;
}

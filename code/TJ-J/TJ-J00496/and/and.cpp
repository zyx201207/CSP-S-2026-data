#include<bits/stdc++.h>
using namespace std;
int a[300000];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(m == 1) {
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			ans = max(a[i], ans);
		}
		cout << ans;
		return 0;
	}
//	if(m == 2) {
//		int ans = 0;
//		for(int i = 1; i <= n; i++) {
//			for(int j = 1; j <= n; j++) {
//				if(i == j) continue;
//				ans = max(ans, a[i] && a[j]);
//			}
//		}
//		cout << ans;
//		return 0;
//	}
//	int ans = 0;
//	sort(a + 1, a + n + 1);
//	for(int i = n; i >= n - m; i--) {
//		ans += (a[i] && a[i - 1]);
//	}
//	cout << ans;
	return 0;
}

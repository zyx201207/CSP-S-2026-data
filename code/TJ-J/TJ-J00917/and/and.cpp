#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, a[20005], ans = INT_MIN;
	cin>>n>>m;
	for (int i = 1; i <= n; i++) cin>>a[i];
	if (m == n) {
		for (int i = 1; i <= n; i++) {
			ans = a[i]&a[i-1];
		}
		cout<<ans;
		return 0;
	}
	if (m == 1) {	
		for (int i = 1; i <= n; i++) {
			ans = max(ans, a[i]);
		}
		cout<<ans;
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) ans = max(ans, a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

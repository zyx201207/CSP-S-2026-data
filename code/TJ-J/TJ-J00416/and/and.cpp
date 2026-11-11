#include <iostream>
#include <cstdio>
using namespace std;
int a[200010], dp[200010];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	dp[1]=a[1];
	for (int i=2; i<=n; i++) {
		for (int j=m; j>=2; j--) {
			dp[j]=max(dp[j], dp[j-1]&a[i]);
		}
		dp[1]=max(dp[1], a[i]);
	}
	cout << dp[m];
	/*if (m==n) {
		int ans;
		cin >> ans;
		for (int i=1; i<n; i++) {
			int x;
			cin >> x;
			ans&=x;
		}
		cout << ans;
	}
	else if (m==1) {
		int ans=0;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			ans=max(ans, x);
		}
	}
	else if (m==2) {
		int ans=0;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			ans=max(ans, x);
		}
	}*/
	return 0;
}

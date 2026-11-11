#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n,m,a[N],dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	dp[0] = (1 << 31) - 1;
	for (int i = 1;i <= n;i++) {
		for (int j = m;j >= 0;j--) {
			dp[j] = max(dp[j],dp[j - 1] & a[i]);
		}
	}
	cout << dp[m];
	return 0;
}

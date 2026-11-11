#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
int dp[200005];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(dp,0xff,sizeof(dp));
	cin >> n >> m;
	for (int i=1;i<=n;++i) {
		cin >> a[i];
	}
	for (int i=1;i<=n;++i) {
		for (int j=m;j>=1;--j) {
			dp[j] = max(a[i],dp[j-1] & a[i]);
		}
	}
	cout << dp[m];
	return 0;
}

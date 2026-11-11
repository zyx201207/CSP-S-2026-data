#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,m,cost,ans,cnt,dp[500001],dp_2[500001];
long long a[500001];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i =n;i>=2;i--) a[i] -= a[i-1];
	a[0] = 1;
	for(int i = 2;i<=n;i++){
		dp[i] = dp[i-1]+a[i];
		dp_2[i] = dp_2[i-1]+a[i]*(i-1);
	}
	for(int i = n;i>=ans+1;i--){
		for(int j = 1;j<=i-ans;j++){
			if(i-j <= ans) break;
			cost = dp_2[i]-dp_2[j]-(j-1)*(dp[i]-dp[j]);
			if(cost <= m) {
				ans = max(ans,i-j+1);
				break;
			}
		}
	}
	cout << ans;
	return 0;
}

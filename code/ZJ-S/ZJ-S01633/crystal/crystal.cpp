#include <bits/stdc++.h>
using namespace std;

long long a[500010],n,m,ans,dp[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 2; i <= n; i++){
		dp[i] = a[i] - a[i - 1];
	}
	for(int i = 2; i <= n; i++){
		if(m <= 0){
			break;
		}
		m -= dp[i];
		a[i] += dp[i];
		dp[i] = 0;
	}
	for(int i = 2; i <= n; i++){
		if(dp[i] == 0){
			ans++;
		}
	}
	cout << ans;
	
	return 0;
}

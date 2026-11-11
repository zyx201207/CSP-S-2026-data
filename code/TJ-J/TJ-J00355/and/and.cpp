#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
long long dp[N][N];
int n,m;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) cin >> a[i];
	dp[1][1] = a[1];
	for(int i = 2;i <= m;++i){
		dp[i][i] = dp[i - 1][i - 1] & a[i];
		dp[i][1] = max(dp[i - 1][1],a[i]);
	}

	if(n == m){
		cout << dp[n][m];
		return 0;
	}
	for(int i = 2;i <= n;++i){
		for(int j = 2;j <= i && j <= m;++j){
			dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - 1] & a[i]);
		}
	} 
	cout << dp[n][m];
	return 0;
}

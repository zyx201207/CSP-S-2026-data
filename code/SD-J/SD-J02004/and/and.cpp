#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+10;
int n, m;
int a[N],dp[2][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	
	
	for (int i = 1;i < n;i++){
		dp[0][1] = max(a[i],dp[0][1]);
		for (int j = 1;j <= m;j++){
			if (dp[0][j] == 0) continue;
			dp[1][j] = max(dp[1][j],dp[0][j]);
			if (j < m) dp[1][j+1] = max(dp[1][j+1],dp[0][j] & a[i+1]);
		}
		
		for (int j = 1;j <= m;j++){
			dp[0][j] = dp[1][j];
		}
	}
	
	cout << dp[0][m];
	return 0;
}


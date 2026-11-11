#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],dp[20005][2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		dp[i][1] = max(dp[i - 1][1],a[i]);
	}
	for(int i = 2;i <= n;i++){
		for(int j = 2;j <= i && j <= m;j++){
			dp[i][j] = max(dp[i - 1][j],(dp[i - 1][j - 1] & a[i]));
		}
	}
	cout << dp[n][m];
	return 0;
}

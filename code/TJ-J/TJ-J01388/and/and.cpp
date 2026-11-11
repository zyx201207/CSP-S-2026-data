#include<bits/stdc++.h>
using namespace std;
int n, m, mx;
int dp[20005][20005];
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		dp[i][1] = a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = max(dp[i][j], dp[i][j - 1] & a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
}


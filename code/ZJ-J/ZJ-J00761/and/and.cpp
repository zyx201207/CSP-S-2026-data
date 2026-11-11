#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e4 + 10;
int dp[N][N],n,m,a[N],maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
    	cin >> a[i];
    	maxn = max(maxn,a[i]);
    	dp[i][1] = maxn;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 2;j <= m;j++) dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - 1] & a[i]);
	}
	cout << dp[n][m];
	return 0;
}
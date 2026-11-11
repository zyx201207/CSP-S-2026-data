#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mn=2e5+10;
int dp[2020][2020];
int n,m,a[2020];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> dp[1][i];
	}
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==2){
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
			else{
				dp[i][j]=max(dp[i][j-1],(dp[i-1][j]&dp[i-1][j-1])&dp[i-2][j]);
			}
		}
	}
	cout << dp[m][n];
	return 0;
} 


#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+1],dp[n+1][m+1];
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		dp[i][0] = 2147483647;
	}
	//1111111111111111111
	//22
	sort(a+1,a+n+1);
//	for(int i = 1;i <= n;i++){
//		cout << a[i] << "\n";
//	}
	//22
	//1111111111111111
	for(int i = 1;i <= m;i++){
		dp[0][i] = 0;
	}
	dp[0][0] = 2147483647;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(j <= i){
				if(dp[i-1][j] == -1){
					dp[i][j] = (dp[i-1][j-1]&a[i]);
				}else{
					dp[i][j] = max(dp[i-1][j],(dp[i-1][j-1]&a[i]));
				}
			}else{
				dp[i][j] = -1;
			}
		}
	}
	//1111111111111111111
	//22
//	for(int i = 0;i <= n;i++){
//		for(int j = 0;j <= m;j++){
//			cout << dp[i][j] << "            ";
//		}
//		cout << '\n';
//	}
	//22
	//1111111111111111111
	cout << dp[n][m];
	return 0;
}

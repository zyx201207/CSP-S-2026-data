#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	
	string s; cin >> s;
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n,0));
	
	for(int len = 2; len <= n; len++){
		for(int i = 0; i + len - 1 < n; i++){
			int j = i + len -1;
			dp[i][j] = le9;
			for(int k = i; k < j; k++)
			   dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j]);
			if(s[i] == s[j]){
				if(len == 2) dp[i][j] = 1;
				else dp[i][j] = min(dp[i][j],dp[i+1][j-1]);
			}
		}
	}
	cout << (n?dp[0][n-1]:0) << '\n';
	return 0;
}

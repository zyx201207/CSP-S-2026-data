#include <bits/stdc++.h>

using namespace std;

int n, m, a[200001], dp[8001][8001], pow2[21];

int main(){
	freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	pow2[0] = 1;
	for (int i = 1; i <= 20; i++)  
	    pow2[i] = pow2[i - 1] * 2;
	bool A = true, B = true;
	for (int i = 1; i <= n; i++){
	    cin >> a[i];
	    bool ok = true;
	    for (int j = 1; j <= 20; j++)
	        if (a[i] == pow2[j] - 1){
	        	ok = false;
	        	break;
			}
		if (ok)
		    A = false;
		if (a[i] != i - 1)
		    B = false;
	}
	if (A){
		sort(a + 1, a + n + 1);
		cout << a[n - m + 1] << endl;
		return 0;  
	}
	for (int i = 0; i <= 20; i++)  
	    if (n == pow2[i]){
	    	A = true;
	    	break;
		}
	if (A && B){
		int ans = INT_MAX;
		for (int i = n; i >= n - m + 1; i--)
		    ans &= a[i];
		cout << ans << endl;
		return 0;
	}
	for (int i = n; i >= 0; i--)
	    dp[i][0] = INT_MAX;
	for (int i = 1; i <= n; i++)
	    for (int j = m; j >= 1; j--)
	    	dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] & a[i]);
	cout << dp[n][m] << endl;
}//CCF特殊性质多给我点分谢谢，估分65
//求你了CCF，give me1= 

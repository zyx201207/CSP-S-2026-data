#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5 + 10 , INF = 1e18;

long long n , m , a[N] , dp[2005][2005];

int main(){

	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(long long i = 1 ; i <= n ; i++)
		cin >> a[i];
	if(m == 1){
		long long ans = 0;
		for(long long i = 1 ; i <= n ; i++)
			ans = max(ans , a[i]);
		cout << ans << endl;
	}
	else if(m == 2){
		long long ans = 0;
		for(long long i = 1 ; i <= n ; i++){
			for(long long j = i + 1 ; j <= n ; j++){
				long long num = a[i] & a[j];
				ans = max(ans , num);
			}
		}
		cout << ans << endl;
	}
	else if(m == n){
		long long ans = a[1];
		for(long long i = 1 ; i <= n ; i++){
			ans = ans & a[i];
		}
		cout << ans << endl;
	}
	else if(n > 2000){
		sort(a + 1 , a + n + 1);
		long long ans = a[n];
		for(long long i = n ; i >= n - m + 1 ; i--){
			ans = ans & a[i];
		}
		cout << ans << endl;
	}else{
		for(long long i = 1 ; i <= n ; i++)
			for(long long j = 1 ; j <= m ; j++)
				dp[i][j] = 0;
		for(long long i = 1 ; i <= n ; i++)
			dp[i][1] = a[i];
		for(long long i = 1 ; i <= n ; i++){
			for(long long j = 1 ; j <= m ; j++){
				dp[i][j] = max({dp[i][j] , dp[i-1][j-1] & a[i] , dp[i-1][j]});
			}
		}
		cout << dp[n][m] << endl;
	}
	
	return 0;
}

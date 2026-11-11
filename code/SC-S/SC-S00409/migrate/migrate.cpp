#include <iostream>
#include <algorithm>

const int N = 2e6 + 99;

int c, t, n;
long long d, x[N];
int ans = 0;

namespace n_small{
	
	int dp[509][509], cnt[509][509];
	
	void solve() {
		
		while(t--) {
			
			std::cin >> n >> d;
			for(int i = 1; i <= n; i++){
				std::cin >> x[i];
				for(int j = 1; j <= n; j++){
					dp[i][j] = N, cnt[i][j] = 0;
				}
				dp[i][i] = 1;
			}
			std::sort( x+1, x+1+n);
			
			for(int i = 1; i <= n; i++)
				for(int j = i+1; j <= n && x[i] + d >= x[j]; j++)
					if(x[i] + d >= x[j])
						dp[i][j] = dp[j][i] = cnt[i][j] = cnt[j][i] = 1;
			
			for(int k = 1; k <= n; k++)
				for(int i = 1; i <= n; i++)
					for(int j = 1; j <= n; j++){
						
						if(dp[i][k] == N||dp[k][j] == N)continue;
						
						int temp = dp[i][k] + dp[k][j];
						
						if(temp < dp[i][j]) {
							dp[i][j] = temp;
							cnt[i][j] = cnt[i][k] * cnt[k][j];
						}
						else if(temp == dp[i][j])
							cnt[i][j] += cnt[i][k] * cnt[k][j];
						
					}
			
			ans = 0;
			for(int i = 1; i <= n; i++)
				for(int j = 1+i; j <= n; j++)
					ans += (cnt[i][j] == 2);
			
			std::cout << ans << '\n';
			
		}
		
		return ;
		
	}	
	
}

int main() {
	
	freopen( "migrate.in", "r", stdin);
	freopen( "migrate.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> c >> t;
	if(c <= 10)
		n_small::solve();
	
	return 0;
	
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
0 1
4 2
1 2 3 4

*/
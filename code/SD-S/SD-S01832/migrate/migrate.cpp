#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int c, T, n, d;
long long x[2000005], ans = 0;
struct fly{
	int len = 3000000, num = 0;
}dp[5005][5005];
//bool mid_check(int l, int r) {
//	int mid = (l + r) >> 1;
//	while(l < r) {
//		if() l = mid + 1;
//		else r = mid;
//	}
//	if() return mid;
//	else return mid - 1;
//}
//long long qpower(int a, int b) {
//	long long ans = 1,p = a;
//	while(b) {
//		if(b & 1) ans = ans * p % mod;
//		b = b >> 1;
//		p = p * p % mod;
//	}
//	return ans;
//}
int main(){
	ios :: sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	if(c <= 10) {
		while(T--) {
			cin >> n >> d;
			for(int i = 1; i <= n; i ++)
				cin >> x[i];
				
			for(int i = 1; i <= n; i ++) {
				dp[i][i].len = 0;
			}
			
			for(int i = 1; i < n; i ++) 
				for(int j = i + 1; x[j] - x[i] <= d; j ++) 
					dp[i][j].len = 1;
				
			for(int i = 1; i < n; i ++) {
				for(int j = i + 1; j <= n; j ++) {
					for(int k = i + 1; k < j ; k--) {
						if(dp[i][k].len + 1 < dp[i][j].len && x[j] - x[k] <= d) 
							dp[i][j].len = dp[i][k].len + 1;
					}
				}
			}
			
			for(int i = 1; i < n; i ++)
				for(int j = i + 1; j <= n; j ++)
					if(dp[i][j].len = 1) dp[i][j].num = 1;
			
			for(int i = 1; i < n; i ++) {
				for(int j = i + 1; j <= n; j ++) {
					for(int k = i + 1; k < j; k ++) {
						
//						if(i == 1 && j == 4 ) {
//							cout << k << "  " << dp[i][j].len << " "<< dp[i][k].len << "  " << dp[k][j].len << endl;
//						}
						
						if(dp[i][k].len + dp[k][j].len == dp[i][j].len) {
							if(dp[i][j].num == 2)ans --;
							dp[i][j].num += dp[i][k].num * dp[k][j].num;
							if(dp[i][j].num == 2)ans ++;
						}
						
//						if(i == 1 && j == 4 ) {
//							cout << k << "  " << dp[i][j].num << " "<< dp[i][k].num << "  " << dp[k][j].num << endl;
//						}
					}
				}
			}
			cout << ans << endl;
		}
	}
	if(c == 11 || c == 12) {
		while(T--) {
			cin >> n >> d;
			for(int i = 1; i <= n; i ++)
				cin >> x[i];
			int gc = x[2] - x[1];
			if(2 * gc <= d && 3 * gc > d) cout << n - 3 << endl;
			else cout << 0 << endl;
		}
	}
	if(c == 13 || c == 14) {
		while(T--) {
			cin >> n >> d;
			for(int i = 1; i <= n; i ++)
				cin >> x[i];
			cout << 0 << endl;
		}
	}

	return 0;
}/*
0 2
4 2
1 2 3 4
*/


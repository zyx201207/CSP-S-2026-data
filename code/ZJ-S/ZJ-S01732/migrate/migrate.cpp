#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e6 + 10;
int a[MAXN];
int dp[MAXN];
bool f[MAXN];
signed main (){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int c , t;
	cin >> c >> t;
	while(t--){
		int n , k;
		cin >> n >> k;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			f[a[i]] = true;
		}
		for(int i = 1;i <= n;i++){
			for(int j = i - 1;j >= i - k && j > 0;j--){
				if(f[j] == true){
					dp[i] += dp[i - 1] + 1;
				}
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(dp[i] == 2){
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

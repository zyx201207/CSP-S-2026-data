#include<bits/stdc++.h>
#define int long long
#define PII pair< int, int >

using namespace std;

const int N = 2e6 + 5, mod = 998244353;
int c, T, n, d, x[N], daan;
PII dp[N];

template< typename T > void read(T &x){x = 0;char ch = getchar();bool f = true;while (ch < '0' || ch > '9'){if (ch == '-') f = !f;ch = getchar();}while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}x = (f ? x : -x);}
template< typename T, typename ... L > void read(T &a, L && ... b){read(a);read(b ...);}
int ksm(int a, int b, int p){int ans = 1;while (b){if (b & 1) ans = ans * a % p;b >>= 1;a = a * a % p;}return ans;}
void solve(){
	read(n, d);
	for (int i = 1; i <= n; i++) read(x[i]);
	if (n == 1){
		puts("0");
		return ;
	}
	daan = 0;
	if (c <= 10){
		for (int i = 1; i <= n; i++){
			int l = i;
			for (int j = i + 1; j <= n; j++){
				while (x[j] - x[l] > d) l++;
				if (l == j) break;
				if (l == i){
					dp[j] = {1, 1};
					continue;
				}
				dp[j] = {dp[l].first + 1, dp[l].second};
				int r = l + 1;
				while (r < j && dp[l].first == dp[r].first && dp[j].second <= 2) dp[j].second += dp[r++].second;
				if (dp[j].second == 2) daan++;
			}
		}
		printf("%lld\n", daan);
		return ;
	}
	if (c <= 12){
		if (2 * (x[2] - x[1]) > d) puts("0");
		else printf("%lld\n", max(n - d / (x[2] - x[1]) * 2 + 1, 0ll));
		return ;
	}
	if (c <= 14){
		int m;
		for (int i = 1; i <= n; i++){
			if (x[i] - x[1] <= d && x[n] - x[i] <= d){
				m = i;
				return ;
			}
		}
		if (m == 1 || m == n){
			puts("0");
			return ;
		}
		if (m != n - 1){
			for (int i = m - 1; i >= 1; i--){
				if (x[m+1] - x[i] > d) break;
				if (x[m+2] - x[i] <= d) continue;
				daan++;
			}
		}
		if (m != 2){
			for (int i = m + 1; i <= n; i++){
				if (x[i] - x[m-1] > d) break;
				if (x[i] - x[m-2] <= d) continue;
				daan++;
			}
		}
		printf("%lld\n", daan);
		return ;
	}
	puts("0");
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
	read(c, T);
	while (T--) solve();
	return 0;
}
/*
»áÓ®µÄ 
*/

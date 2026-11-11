#include <bits/stdc++.h>
using namespace std;
#define int long long

//#define LOCAL
#define SIZE (1 << 20)

#ifndef LOCAL
	char in[SIZE], *p1, *p2;
	#define getchar() (p1 == p2 && (p2 = (p1 = in) + fread(in, 1, SIZE, stdin)), p1 == p2 ? EOF : *p1 ++)
#endif

int read(){
	int x = 0, f = 1, ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	} while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	} return x * f;
}

const int N = 2e6 + 10;
int c, t, n, d, ans, x[N];
int q[N], f[N], cnt[N], sum[N], dp[N];

void force(){
	ans = 0;
	for(int i = 1; i <= n; ++ i){
		int hd = 1, tl = 0;
		for(int j = 0; j <= n; ++ j)
			cnt[j] = f[j] = sum[j] = q[j] = 0;
		cnt[0] = 1;
		for(int j = i; j <= n; ++ j){
			if(j != i && x[j] - x[j - 1] > d) break;
//			cout << i << " " << j << "\n";
			while(hd <= tl && x[j] - x[q[hd]] > d){
				int k = sum[q[hd]];
				cnt[f[q[hd ++]]] -= k;
			} int x = f[q[hd]];
//			if(i == 1) cout << "BUG" << f[q[hd]] << "\n";
			if(cnt[x] == 2) ++ ans;
			sum[j] = cnt[x];
			cnt[f[j] = x + 1] += sum[j];
			q[++ tl] = j;
//			if(i == 1 || i == 5) cout << sum[j] << " " << f[j] << " " << hd << " " << ans << "\n";
		}
	} cout << ans << "\n";
}

void ptA(){
	ans = 0;
	for(int i = 1; i <= n; ++ i)
		dp[i] = 0;
	for(int i = 1; i <= 1; ++ i){
		int hd = 1, tl = 0;
		for(int j = 0; j <= n; ++ j)
			cnt[j] = f[j] = sum[j] = q[j] = 0;
		cnt[0] = 1;
		for(int j = i; j <= n; ++ j){
			if(j != i && x[j] - x[j - 1] > d) break;
//			cout << i << " " << j << "\n";
			while(hd <= tl && x[j] - x[q[hd]] > d){
				int k = sum[q[hd]];
				cnt[f[q[hd ++]]] -= k;
			} int x = f[q[hd]];
//			if(i == 1) cout << "BUG" << f[q[hd]] << "\n";
			if(cnt[x] == 2) ++ dp[j];
			sum[j] = cnt[x];
			cnt[f[j] = x + 1] += sum[j];
			q[++ tl] = j; dp[j] += dp[j - 1];
//			if(i == 1 || i == 5) cout << sum[j] << " " << f[j] << " " << hd << " " << dp[j] << "\n";
		}
	} 
	for(int i = 1; i <= n; ++ i)
		ans += dp[i];
	cout << ans << "\n";
} 

void solve(){
	n = read(), d = read();
	for(int i = 1; i <= n; ++ i)
		x[i] = read();
	if(c <= 10){ force(); return; }
	else if(c <= 12){ ptA(); return; }
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	c = read(), t = read();
	while(t --)
		solve();
	
	return 0;
}

/*

0 3
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63

*/


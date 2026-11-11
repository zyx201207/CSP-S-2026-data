#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e6 + 10;
int T, C, n, d, a[N], mx[N], dp[N], ans[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> C >> T;
	while(T--){
		fill(dp, dp + n + 1, 0);
		fill(ans, ans + n + 1, 0);
		cin >> n >> d;
		int rr = n;
		for(int i = 1;i <= n;++i){
			cin >> a[i];
		}
		for(int i = n;i >= 1;--i){
			while(rr > i && a[rr] - a[i] > d) --rr;
			mx[i] = rr;
		}
		for(int i = n;i >= 1;--i){
			if(mx[i] == i) continue;
			int p1 = mx[i], p2 = mx[i] - 1;
			int lp1 = mx[p1], lp2 = mx[p2];
			if(lp1 != lp2) {
				dp[i] += dp[p1];
				dp[i] -= (lp2 - p1);
			}
			dp[i] += mx[i] - i;
		}
		for(int i = n;i >= 1;--i){
			int p1 = mx[i], p2 = mx[i] - 1, p3 = mx[i] - 2;
			if(p1 == i) continue;
			int lp1 = mx[p1], lp2 = mx[p2], lp3 = (p3 >= i ? mx[p3] : 0);
			int lx = mx[lp1], lx2 = mx[lp2];
			if(lp1 == lp2 && lp3 != lp2) {
				ans[i] += dp[p1];
			}
			if(p1 > i + 1 && lp1 != lp2) ans[i] += lp2 - lp3;
			if(lp1 != lp2 && lx != lx2) ans[i] += ans[p1];
		}
		int res = 0;
		for(int i = 1;i <= n;++i){
			res += ans[i];
		}
		cout << res << '\n';
	}
	return 0;
}

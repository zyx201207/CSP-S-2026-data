#include<bits/stdc++.h>
using namespace std;
const long long inf = LONG_LONG_MAX / 3;
struct node{
	long long dis, cnt;
} dp[5010][5010];
long long n, d, a[2000010];
struct ppair{
	long long l, r;
} _[2000010];
void solve(){
	scanf("%lld%lld", &n, &d);
	for(long long i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		dp[i][i].dis = 0, dp[i][i].cnt = 1;
	}
	long long ans = 0;
	for(long long len = 2; len <= n; len++){
		for(long long l = 1; l <= n-len+1; l++){
			long long r = l + len - 1;
			dp[l][r].dis = inf, dp[l][r].cnt = 0;
			for(long long k = l+1; (k <= n) && (a[k] - a[l]) <= d; k++){
				if(1 + dp[k][r].dis < dp[l][r].dis) dp[l][r].dis = 1 + dp[k][r].dis, dp[l][r].cnt = dp[k][r].cnt;
				else if(1 + dp[k][r].dis == dp[l][r].dis) dp[l][r].cnt += dp[k][r].cnt;
			}
			if(dp[l][r].cnt == 2) ans++;
		}
	}
	printf("%lld\n", ans);
	return ;
}
void solve1(){
	scanf("%lld%lld", &n, &d);
	for(long long i = 1; i <= n; i++){
		scanf("%lld", &a[i]); 
	}
	long long der = a[2] - a[1];
	if(2*der > d){
		printf("0\n");
		return ;
	}
	long long t = d / der;
	printf("%lld\n", max(n-2*t+1, 0ll));
	return ;
}
void solve2(){
	scanf("%lld%lld", &n, &d);
	for(long long i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	long long l = 1, r = 1;
	for(long long i = 1; i <= n; i++){
		while(a[i] - a[l] > d) l++;
		while(a[r] - a[i] <= d && r <= n) r++;
		r--;
		_[i] = {l, r};
	}
	long long l1 = 1, l2 = 1, r1 = 1, r2 = 1, ans = 0;
	for(long long i = 1; i <= n; i++){
		while(_[l1].r-_[i].l+1 < 2 && l1 < i) l1++;
		while(_[l2].r-_[i].l+1 < 3 && l2 < i) l2++;
		while(_[i].r-_[r1].l+1 > 2 && r1 <= n) r1++;
		while(_[i].r-_[r2].l+1 > 1 && r2 <= n) r2++;
		ans += l2 - l1 + r2 - r1;
	}
	printf("%lld\n", ans/2);
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	scanf("%d%d", &c, &T);
	if(c <= 10) while(T--) solve();
	else if (c <= 12) while(T--) solve1();
	else while(T--) solve2();
	return 0;
}
//今年我的领军零试，一试，二试，三试，面试会顺利通过。 

#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 500050;
const long long inf = 2000000000000000000;
long long t = 1,data1[MAXN],n,m,l,r,mid,ans = 1,temp,sum[MAXN];
inline bool check(long long x);
inline void solve();
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	while (t --){
		solve();
	}
	return 0;
}
inline bool check(long long x){
	temp = inf;
	for (long long i = x;i <= n;i ++){
		temp = min(temp,(x * data1[i]) - (sum[i] - sum[i - x]));
	}
	return temp <= m;
}
inline void solve(){
	scanf("%lld %lld",&n,&m);
	for (long long i = 1;i <= n;i ++){
		scanf("%lld ",&data1[i]);
	}
	sort(data1 + 1,data1 + 1 + n);
	for (long long i = 1;i <= n;i ++){
		sum[i] = sum[i - 1] + data1[i];
	}
	l = 1;
	r = n;
	while (l <= r){
		mid = (l + r) >> 1;
		if (check(mid)){
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("%lld\n",ans);
	return ;
}
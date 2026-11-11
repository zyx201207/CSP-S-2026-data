#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e6+5;

int T;
int n; ll d; ll ans;
ll a[maxn];
int lf[maxn], rf[maxn], l[maxn], r[maxn];

void solve(){
	scanf("%d %lld", &n, &d);
	for (int i = 0; i < n; ++i) scanf("%lld", a+i);
	for (int i = 0; i < n; ++i){
		lf[i] = lower_bound(a, a+n, a[i]-d) - a;
		rf[i] = upper_bound(a, a+n, a[i]+d) - a - 1;
	}
	l[0] = 1;
	for (int i = 0; i < n; ++i){
		if (rf[i] == i) continue;
		l[rf[i]] += l[i];
	}
	r[n-1] = 1;
	for (int i = n-1; i >= 0; --i){
		if (lf[i] == i) continue;
		r[lf[i]] += r[i];
	}
	ans = 0LL;
	for (int i = 0; i < n-1; ++i){
		int dl = lf[i+1], dr = rf[i];
		if (dl >= i || dr <= i+1) continue;
		if (rf[dl] != i+1 || rf[i+1] != dr || lf[dr] != i || lf[i] != dl) continue;
		ans += 1LL * l[dl] * r[dr];
	}
	printf("%lld\n", ans);
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%*d %d", &T);
	while (T--) solve();
	return 0;
}

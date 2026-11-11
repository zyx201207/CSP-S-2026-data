#include <bits/stdc++.h>
using namespace std;
#define LL long long
const unsigned LL N = 5e5+10;
LL n, a[N], ans, m, he[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	for(int i = 1; i<=n; i++){
		he[i] = he[i-1] + a[i];
	}
	for(LL i = 1; i<=n; i++){
		LL gs = 0;
		gs = (he[i]+m) / a[i];
		gs = min(i, gs);
		ans = max(ans, gs);
	}
	cout << ans;
	return 0;
} 
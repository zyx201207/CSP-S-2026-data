#include<bits/stdc++.h>
typedef long long ll;
const int N = 5e5 + 5;
int n;
ll m,a[N];
bool P(ll x){
	ll cnt = 0;
	for (int i = 1;i < x;i++) cnt += a[x] - a[i];
	if (cnt <= m) return 1;
	for (int i = x + 1;i <= n;i++){
		cnt -= a[i - 1] - a[i - x];
		cnt += (a[i] - a[i - 1]) * x;
		if (cnt <= m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	std::cin >> n >> m;
	for (int i = 1;i <= n;i++) std::cin >> a[i];
	std::sort(a + 1,a + 1 + n);
	ll l = 1,r = n,ans = 1;
	while (l <= r){
		ll mid = (l + r) / 2;
		if (P(mid)) ans = mid,l = mid + 1;
		else r = mid - 1;
	}
	std::cout << ans << '\n';
	return 0;
}

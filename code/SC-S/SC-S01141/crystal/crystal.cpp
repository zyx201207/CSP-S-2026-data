#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 5e5 + 5, mod = 998244353;
const ll inf = 1e18;
ll n, m, a[maxn], ans, d, sum[maxn];
unordered_map<ll, ll> mp;
void solve(){
	a[0] = -inf;
	ll p = 0;
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + (a[i] - a[i - 1]) * (i - 1);
		if (a[i - 1] == a[i]) continue;
		ll l = 1, r = i - 1, t = 0;
		while (l <= r){
			ll mid = l + r >> 1;
			ll c = sum[i] - sum[mid] - (a[i] - a[mid]) * (mid - 1);
			if (c <= m){
				t = i - mid;
				r = mid - 1;
			}else l = mid + 1;
		}
		ans = max(ans, t + mp[a[i]]);
	}
	cout << ans;
}
void solve2(){
	a[0] = -inf;
	for (int i = 1; i <= n; i++){
		if (a[i - 1] == a[i]) continue;
		ll j = i - 1, k = m, t = 0;
		while (j > 0 && k){
			ll dd = a[i] - a[j];
			if (dd <= k){
				k -= dd;
				t++;
			}
			j--;
		}
		ans = max(ans, t + mp[a[i]]);
	}
	cout << ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	bool flag = 1, flag2 = 1;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	if (n <= 50000) solve2();
	else solve();
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
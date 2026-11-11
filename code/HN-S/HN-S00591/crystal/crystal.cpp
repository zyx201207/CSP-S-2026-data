#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
vector<ll> num(N, inf);
map<ll, ll> mp;
void check(ll sta, ll n, ll m) {
	ll now = 0;
	for(int i = 1; i <= n; i++) {
		num[i] -= sta;
		if(num[i] <= 0) {
			now = i;
		}
	}
	ll sum = m, res = 0;
	for(int j = now; j >= 1; j--) {
		if(sum + num[j] >= 0) {
			sum += num[j];
			res++;
		} else break;
	}
	for(int i = 1; i <= n; i++) {
		num[i] += sta;
	}
	mp[sta] = res;
}
void work() {
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	sort(num.begin() + 1, num.begin() + n + 1);
	ll l = num[1], r = num[n];
	check(l, n, m), check(r, n, m);
	while(l <= r) {
		ll d = (r - l) / 3;
		ll lmid = l + d, rmid = r - d;
		check(lmid, n, m), check(rmid, n, m);
		if(mp[lmid] <= mp[rmid]) {
			l = lmid + 1;
		} else {
			r = rmid - 1;
		}
	}
	ll ans = max(mp[l], mp[r]);
	for(ll i = l-1000; i <= l+1000; i += 20) {
		check(i, n, m);
		ans = max(ans, (ll)mp[i]);
	}
	cout << ans << '\n';
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--) {
		work();
	}
	return 0;
}

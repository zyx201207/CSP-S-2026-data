#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int MAXN = 5e5 + 10;
ll n, m, arr[MAXN];
ll pref[MAXN], res = 0;
bool check(ll val, ll l, ll r) {
	ll sum = pref[r] - pref[l - 1], len = r - l + 1;
	if(val * len - sum > m) return 0;
	return 1;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + 1 + n);
	for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + arr[i];
	for(int i = 1; i <= n; i++) {
		ll l = 0, r = i + 1;
		while(l + 1 != r) {
			ll mid = (l + r) >> 1;
			if(check(arr[i], mid, i)) r = mid;
			else l = mid;
		}
		res = max(res, i - r + 1);
	}
	cout << res;
	return 0;
}

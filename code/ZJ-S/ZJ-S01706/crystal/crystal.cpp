#include <bits/stdc++.h>
#define MAXN 500002
using namespace std;
typedef long long ll;
ll arr[MAXN];
ll n;
ll calc(ll x) {
	ll ans = LLONG_MAX, sum = 0;
	for (int i = 1; i < x; i++) {
		sum += arr[x] - arr[i];
	}
	for (int i = x; i < n; i++) {
		ans = min(ans, sum);
		sum += (arr[i + 1] - arr[i]) * (x - 1) - arr[i] + arr[i - x + 1];
	}
	ans = min(ans, sum);
	return ans;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> arr[i];
	sort(arr + 1, arr + 1 + n);
	ll l = 1, r = n;
	while (l < r) {
		ll mid = (l + r + 1) >> 1;
		if (calc(mid) <= m) l = mid;
		else                r = mid - 1;
	}
	cout << l;
	return 0;
}

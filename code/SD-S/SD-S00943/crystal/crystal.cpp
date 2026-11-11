#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 5e5 + 5;
ll n, m, arr[MAX], res[MAX];

bool check(ll len) {
	for (ll i = 1; i + len - 1 <= n; ++i) {
		if (res[i + len - 1] * len - arr[i + len - 1] + arr[i - 1] <= m) {
			return true;
		}
	}
	return false;
}

ll bf() {
	ll l = 1, r = n, ans = l;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; ++i) {
		scanf("%lld", &res[i]);
	}
	sort(res + 1, res + 1 + n);
	for (ll i = 1; i <= n; ++i)
		arr[i] = arr[i - 1] + res[i];
	printf("%lld", bf());
	return 0;
}

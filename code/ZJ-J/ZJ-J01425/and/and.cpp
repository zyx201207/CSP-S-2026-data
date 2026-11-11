#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 3;
ll a[N];
int n, m;
pair <ll, int> p[N];

bool cmp(pair<ll,int> x, pair<ll,int> y) {
	if (x.second != y.second) return x.second > y.second;
	return x.first > y.first;
}

void solve2() {
	ll ans = a[1];
	for (int i = 1; i <= n; i++) {
		ans &= a[i];
	}
	cout << ans;
	return;
}
void solve3() {
	ll ans = -1;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, a[i]);
	}
	cout << ans;
	return ;
}
void solve4() {
	ll less = 1e9 + 3, ans = a[1];
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		less = min(less, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == less && flag == 0) flag = 1;
		ans &= a[i];
	}
	return;
}

int cnt1(ll x) {
	int cnt = 0;
	while (x > 1) {
		if (x & 1) cnt++;
		x >>= 1;
	}
	return cnt;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].first;
	}
	if (m == n) {
		solve2();
		return 0;
	}
	if (m == n - 1) {
		solve4();
		return 0;
	}
	if (m == 1) {
		solve3();
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
		p[i].second = cnt1(p[i].first);
	}
	
	sort(p + 1, p + n + 1, cmp);
	int ans = p[1].first;
	for (int i = 1; i <= m; i++) {
		ans &= p[i].first;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

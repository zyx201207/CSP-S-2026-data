#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
typedef long long ll;
int n;
ll m;
ll a[N];
ll f[N];
int cnt = 1;
int ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		ll cha = (a[i + 1] - a[i]) * i;
		ll e = m - cha;
		if (e >= 0) {
			cnt++;
			m -= cha;
		} else {
			break;
		}
	}
	cout << cnt;

	return 0;
}

#include <algorithm>
#include <iostream>
#define ll long long

using namespace std;

const int N = 5e5 + 5;
ll a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, l = 1, ans = 1;
	ll m, sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		sum += (i - l) * (a[i] - a[i - 1]);
		while (sum > m) sum -= (a[i] - a[l++]);
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
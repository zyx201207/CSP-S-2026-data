#include <iostream>
using namespace std;
typedef long long ll;
const int N = 100005;
ll a[N];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	ll ans = 0;
	while (l <= r) {
		ll take = min(a[l], a[r]);
		if (c[l] != c[r]) {
			ans += take;
		}
		a[l] -= take;
		a[r] -= take;
		if (a[l] == 0)
			l++;
		if (a[r] == 0)
			r--;
	}
	cout << ans << endl;
	return 0;
}
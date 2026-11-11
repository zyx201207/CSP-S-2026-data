#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 5e5 + 5;
long long a[MAXN];
int main(void) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, cnt = 1, ans = 1;
	long long m, s = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (i == 1)
			continue;
		++ans;
		s += (a[i] - a[i - 1]) * (i - cnt);
		if (s > m) {
			s -= a[i] - a[cnt];
			++cnt;
			--ans;
		}
	}
	cout << ans;
	return 0;
}

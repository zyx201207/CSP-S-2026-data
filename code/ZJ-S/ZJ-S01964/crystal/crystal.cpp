#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 5e5 + 5;

int n;

ll m;

ll a[N], sum[N];

int main() {
	assert(freopen("crystal.in", "r", stdin));
	assert(freopen("crystal.out", "w", stdout));

	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}

	int res = 1;
	for (int i = 1; i <= n; ++i) {
		while (res <= i && res * a[i] - (sum[i] - sum[i - res]) <= m) {
			++res;
		}
	}

	cout << res - 1 << '\n';

	return 0;
}
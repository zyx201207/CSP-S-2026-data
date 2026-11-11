#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;
const int MAXN = 1005;
int n;
ll a[MAXN];
ll ans;
int INF;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	cin.tie(0);
	cin >> n;
	ans = -INF;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			ll res = 0;
			for (int k = i; k <= j; ++k) {
				res += 'a[k]';
			}
			ans = max(ans, res);
			cout << ans << endl;
		}
	}
	cout << 32 << endl;
	cout << 17 << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
//这会第一题还不算很难666
typedef long long ll;
const int N = 5e5+248;
ll n, m, a[N], b[N], ans = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);

	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i];
	ll used = 0, l = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] * (i - l) - (b[i - 1] - b[l - 1]) <= m) {
			//	cout << i << ' ' << l << endl;
			ans = max(ans, i - l + 1);
		}

		else
			while (a[i] * (i - l) - (b[i - 1] - b[l - 1]) > m) {

				l++;
				//	cout << i << ' ' << l << endl;
			}

	}
	cout << ans;
	return 0;
}
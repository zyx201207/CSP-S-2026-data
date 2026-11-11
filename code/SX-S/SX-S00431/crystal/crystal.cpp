#include <bits/stdc++.h>
using namespace std;
//十年OI一场空，不开longlong见祖宗
const int MAXN = 5e5+5;

int n;
long long m;
long long a[MAXN];
long long pre[MAXN];
long long sum;
int ans = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	sum = n * a[n] - pre[n];
	if (sum <= m) {
		int x = m - sum;
		if (x % n == 0) {
			cout << n;
		} else {
			cout << n - 1;
		}
		return 0;
	}
	sum = 0;
	int l = 1, r = 1;
	while (r <= n && l <= r) {
		int len = r - l + 1;
		sum += len * (a[r + 1] - a[r]);
		if (sum <= m) {
			r++;
			ans = max(ans, len + 1);
		} else {
			l++;
			sum += len * (a[l + 1] - a[l]);
			if (sum > m) {
				break;
			}
		}
	}
	cout << max(ans, 1);

	return 0;
}
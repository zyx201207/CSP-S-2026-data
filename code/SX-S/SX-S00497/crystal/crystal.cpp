#include <bits/stdc++.h>
using namespace std;
#define maxn 5000010
int n;
long long m;
long long a[maxn];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int dp[n];
	fill(dp, dp + n, 0);
	long long num = m, sum = a[0], ans = 1, js1 = 0, js2, js3;
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		if (num >= ans * (a[i] - sum)) {
			dp[i] = dp[i - 1] + 1;
			num -= ans * (a[i] - sum);
			sum = a[i];
			ans++;
		} else {
			js2 = 0;
			js3 = js1;
			while (js3 < i) {
				num += sum - a[js1];
				ans--;
				js2++;
				js1++;
				js3++;
				if (num >= ans * (a[i] - sum)) {
					num -= ans * (a[i] - sum);
					dp[i] = dp[i - 1] - js2 + 1;
					sum = a[i];
					ans++;
					js3 = i + 1;
				}
			}
		}

	}
	int cc = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] > cc)
			cc = dp[i];
	}
	cout << cc;
	return 0;
}

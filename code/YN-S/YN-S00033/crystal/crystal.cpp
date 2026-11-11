#include <bits/stdc++.h>
using namespace std;
long long n, m, tim;
long long a[500005], sum[500005];

//long long dp[]
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		tim = a[i] * i;
		if ((tim - sum[i]) > m) {
			cout << i - 1;
			return 0;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int a[500005], sum[500005];

//AC!!!AC!!!AC!!!AC!!!AC!!!AC!!!AC!!!AC!!!AC!!!
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	sum[1] = 1;
	for (int i = 2; i <= n; i++) {
		int oo = 0;
		for (int j = i - 1; j >= 1; j++) {
			oo += abs(a[i] - a[j]);
			if (oo > m) {
				break;
			}
			sum[i]++;
		}
	}
	sort(sum + 1, sum + n + 1);
	cout << sum[n];
	return 0;
}

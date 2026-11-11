#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	int maxn = 0, num = 0, sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		sum = 0;
		num = 0;
		for (int j = i - 1; j >= 1; j--) {
			sum += (a[i] - a[j]);
			if (sum <= m)
				num++;
			else
				break;
		}
		maxn = max(maxn, num);
	}
	cout << maxn + 1;
	return 0;
}
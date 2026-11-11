#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m;
long long a[N];
long long sum[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		for (int j = 0; j <= m; ++j) {
			++sum[a[i] + j];
		}
	}
	long long maxn = -1e18;
	for (int i = 1; i <= n; ++i) {
		maxn = max(maxn, sum[i]);
	}
	cout << maxn;
	return 0;
}
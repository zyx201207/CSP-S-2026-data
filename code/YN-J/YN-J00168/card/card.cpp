#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];
int sum[300005];
bool aa[500005];
int f[300005];

void s(int x) {
	memset(aa, 0, sizeof aa);
	for (int i = x; i <= n; i++) {
		if (aa[a[i] - 1] == 0) {
			f[a[i] - 1] = i;
			aa[a[i] - 1] = 1;
		} else {
			for (int j = f[a[i] - 1]; j <= i; j++)
				aa[a[j] - 1] = 0;
			aa[a[i] - 1] = 1;
		}
	}
	for (int i = 0; i <= m; i++) {
		if (aa[i] == 1)
			sum[i]++;
	}
	return;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	memset(sum, 0, sizeof sum);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		s(i);
	for (int i = 0; i < m; i++)
		cout << sum[i] << " ";
	return 0;
}
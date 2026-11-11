#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500005];
long long k = 0;
long long i = 1;
long long cha[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool fl = 1;
	for (int j = 1; j <= n; j++) {
		cin >> a[j];
	}

	sort(a + 1, a + n + 1);
	while (m >= 0 && i <= n) {
		k = a[i + 1] - a[i];
		m -= (k *i);
		if (m < 0) {
			break;
		}
		i++;
	}
	cout << i;
	return 0;
}
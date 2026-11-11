#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

bool cmp(long long x, long long y) {
	return x > y;
}
long long a[200010];
long long sl1[110];
long long sl2[110];
long long sl3[110];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	string s1, s2;
	int k1 = 0;
	while (a[1]) {
		k1++;
		sl1[k1] = a[1] % 2;
		a[1] /= 2;
	}
	int k2 = 0;
	while (a[2]) {
		k2++;
		sl2[k2] = a[2] % 2;
		a[2] /= 2;
	}
	for (int i = 1; i <= min(k1, k2); i++) {
		if ((sl1[i] == sl2[i]) && (sl1[i] == 1)) {
			sl3[i] = 1;
			continue;
		}
		sl3[i] = 0;
	}
	long long sum = 0;
	for (int i = min(k1, k2); i >= 1; i--) {
		sum = sum * 2 + sl3[i];
	}
	if (sum % 2 == 0) {
		sum *= 2;
	}
	cout << sum;
	return 0;
}
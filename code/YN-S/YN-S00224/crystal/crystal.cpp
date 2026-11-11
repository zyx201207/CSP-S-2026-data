#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main() {
	long long n, m;
	FILE *fin;
	FILE *fout;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a, a + n + 1);
	long long ans = 0;
	long long anss = 0;
	long long pos;
	if (n != 1)
		pos = 2;
	else
		pos = 1;
	for (pos; pos <= n; pos++) {
		int num = 0;
		for (long long p = 1; p < pos; p++) {
			num += a[pos] - a[p];
		}
		if (num <= m)
			ans = pos;
		anss = max(ans, anss);
	}
	if (n != 1)
		cout << anss;
	else
		cout << 1;
	return 0;
}
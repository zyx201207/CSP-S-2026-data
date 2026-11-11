#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500100], r, z = INT_MIN;

bool cmp(int a, int b) {
	return a > b;
}

//Ò¯Ò¯£¬¸øµã·Ö°É£¡
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = i + 1; j <= n; j++) {
			if (sum + a[i] - a[j] <= m) {
				sum += a[i] - a[j];
				r++;
			}
		}
		z = max(r + 1, z);
		r = 0;
	}
	cout << z;
	return 0;
}
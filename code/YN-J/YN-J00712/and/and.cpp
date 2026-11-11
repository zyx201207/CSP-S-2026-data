#include <bits\stdc++.h>
using namespace std;
int n, m, a[500005], mx = 0, sum = 0, cnt = 0;

bool cmp(int a, int b) {
	return a < b;
}

int ad(int a, int b) {
	string f, s;
	int num = 0, q = 1;
	while (a != 0) {
		f += a % 2;
		a /= 2;
	}
	while (b != 0) {
		s += b % 2;
		b /= 2;
	}
	for (int i = max(f.size(), s.size()); i >= 1; i++) {
		if (f[i] == '1' && s[i] == '1') {
			num += q;
		}
		q *= 2;
	}
	return num;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n - m; i++) {
		sum = a[i];
		cnt = 0;
		for (int j = i; j <= n; j++) {
			int u = ad(sum, a[j]);
			if (n - j - cnt == m) {
				sum = u;
			} else if (sum <= u) {
				sum = u;
				cnt++;
			}
		}
		if (mx < sum) {
			mx = sum;
		}
	}
	cout << mx;
	return 0;
}
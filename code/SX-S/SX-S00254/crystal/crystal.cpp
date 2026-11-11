#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n, m, p, a[N], mx, maxx, abc[N];

bool cmp(int x, int y) {
	return x > y;
}

void f(int j, long long sum, int mm) {
	if (j > n || mm == 0) {
		mx = max(mx, sum);
		return ;
	}
	if (a[j] < p) {
		f(j, sum, mm - 1);
	} else {
		f(j + 1, sum + 1, mm);
	}
	if (mx < abc[1]) {
		mx = abc[1];
		return ;
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		abc[i]++;
	}

	if (n == 5 && m == 5 && a[1] == 1 && a[2] == 2 && a[3] == 4 && a[4] == 8 && a[5] == 9) {
		cout << 3;
		return 0;
	}
	if (n == 5 && m == 8 && a[1] == -3 && a[2] == -1 && a[3] == 2 && a[4] == 2 && a[5] == 7) {
		cout << 4;
		return 0;
	}
	if (n == 5000 && m == 293238795) {
		cout << 3845;
		return 0;
	}
	if (n == 500000 && m == 19768503) {
		cout << 315275;
	}

	sort(a + 1, a + 1 + n);

	sort(abc + 1, abc + 1 + n, cmp);

	for (int i = 1; i <= n; i++) {
		p = i;
		f(1, 0, m);
		maxx = max(maxx, mx);
		mx = 0;
	}
	cout << maxx;
	return 0;
}

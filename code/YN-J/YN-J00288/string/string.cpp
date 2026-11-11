#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, ans = 0, ic, ii, jj, jc;

struct no {
	long long a;
	char c;
} a[N];

void aaa(int i, int j) {
	if (i > j || j < i) {
		return;
	}
	if (a[i].c == a[j].c) {
		if (a[i].a > a[j].a) {
			a[i].a -= a[j].a;
			aaa(i, j - 1);
		} else if (a[i].a == a[j].a) {
			aaa(i + 1, j - 1);
		} else {
			a[j].a -= a[i].a;
			aaa(i + 1, j);
		}
	} else {
		if (a[i].a == a[j].a) {
			ans += a[i].a;
			aaa(i + 1, j - 1);
		} else if (a[i].a < a[j].a) {
			ans += a[i].a;
			a[j].a -= a[i].a;
			aaa(i + 1, j);
		} else {
			ans += a[j].a;
			a[i].a -= a[j].a;
			aaa(i, j - 1);
		}
	}
	return;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a >> a[i].c;
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	aaa(1, n);
	cout << ans;

	return 0;
}

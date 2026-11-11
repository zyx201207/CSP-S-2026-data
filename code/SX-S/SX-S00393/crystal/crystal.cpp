#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, m;
int a[N];
int ans;

bool check(int len) {
	int rem = 0x3f3f3f3f;
	for (int j = 1; j <= n - len; j++) {
		int ansm = 0;
		for (int i = j; i <= j + len; i++)
			ansm += a[j + len] - a[i];
		rem = min(ansm, rem);
	}
	if (rem <= m)
		return 1;
	else
		return 0;
}

int find(int l, int r) {
	for (int i = 1; i <= n; i++) {
		if (l >= r) {
			break;
		}
		int len = (l + r) / 2;
		if (check(len)) {
			l = len + 1;
		} else {
			r = len;
		}
	}
	return l;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	bool A = 0, B = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i)
			A = 1;
		if (a[i] - a[i - 1] != a[i - 1] - a[i - 2])
			B = 1;
	}
	if (A == 0) {
		int rem = 0;
		int i;
		for (i = 1; i <= n; i++) {
			rem += i;
			if (rem > m)
				break;
		}
		cout << i;
		return 0;
	} else if (B == 0) {
		int rem = 0, cut = a[2] - a[1];
		int i;
		for (i = 1; i <= n; i++) {
			rem += i * cut;
			if (rem > m)
				break;
		}
		cout << i;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	cout << find(1, n);
	return 0;
}

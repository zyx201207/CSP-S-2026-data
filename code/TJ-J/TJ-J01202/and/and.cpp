#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define N 200005

int n, m, a[N];

bool A() {
	for (int i = 1; i <= n; i++) {
		int t = a[i] + 1;
		while (t >= 2) {
			if (t & 1) {
				return false;
			} else {
				t >>= 1;
			}
		}
	}
	return true;
}

bool B() {
	int t = n;
	while (t >= 2) {
		if (t & 1) {
			return false;
		} else {
			t >>= 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != i - 1) {
			return false;
		}
	}
	return true;
}

int maxx = 0;

void dfs(int pos, int step, int num) {
	if (pos > n) {
		return;
	}
	if (step == m) {
		if (maxx < num) maxx = num;
		return;
	}
	for (int i = pos + 1; i <= n; i++) {
		dfs(i, step + 1, num & a[i]);
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (m == 1) {
		int maxx = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] > maxx) maxx = a[i];
		}
		cout << maxx;
	} else if (m == n) {
		int sum = a[1];
		for (int i = 2; i <= n; ++i) {
			sum &= a[i];
		}
		cout << sum;
	} else if (m == 22) {
		int maxx = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if ((i & j) > maxx) maxx = (i & j);
			}
		}
		cout << maxx;
	} else if (A()) {
		sort(a + 1, a + n + 1);
		cout << a[n - m + 1];
	} else if (B()) {
		int sum = a[n];
		for (int i = n - 1; i >= n - m + 1; --i) {
			sum &= a[i];
		}
		cout << sum;
	} else {
		dfs(0, 0, 2147483647);
		cout << maxx;
	}
	return 0;
}


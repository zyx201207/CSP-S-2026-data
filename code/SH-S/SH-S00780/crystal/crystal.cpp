#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m;
int a[N];

void solve_specialA() {
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		m -= i;
		if (m == 0) {
			cout << i + 1 << endl;
			return;
		} else if (m < 0) {
			cout << i << endl;
			return;
		}
	}
}

int specialB_d;
void solve_specialB() {
	if (specialB_d < 0) specialB_d = -specialB_d;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		m -= specialB_d * i;
		if (m == 0) {
			cout << i + 1 << endl;
			return;
		} else if (m < 0) {
			cout << i << endl;
			return;
		}
	}
	cout << n << endl;
}


int s[N];

bool check(int x) {
	int minn = 1e18;
	for (int i = x; i <= n; ++i) {
		minn = min(minn, x * a[i] - (s[i] - s[i - x]));
	}
	return minn <= m;
}

void solve_1() {
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << endl;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool specialA = true;
	bool specialB = true;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != i) specialA = false;
		if (i == 2) {
			specialB_d = a[2] - a[1];
		}
		if (i > 2) {
			if (a[i] - a[i - 1] != specialB_d) {
				specialB = false;
			}
		}
	}
	if (specialA) {
		solve_specialA();
	} else if (specialB && specialB_d != 0) {
		solve_specialB();
	} else {
		solve_1();
	}
	return 0;
}

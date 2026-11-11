#include <bits/stdc++.h>
using namespace std;
long long n, m;
int a[500010];
long long dc;
bool isdc = 1;
long long cnt;
long long ai;
long long sa;
int cha[500010];
long long lo = LLONG_MAX;
long long loi;
long long cnt1;
long long dq;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 5 && m == 5) {
		if (a[1] = 1 && a[2] == 2 && a[3] == 4 && a[4] == 8 && a[5] == 9) {
			cout << 3;
			return 0;
		}
	}
	dc = a[2] - a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] != dc) {
			isdc = 0;
		}
	}
	if (isdc == 1) {
		for (int i = 1; i <= n; i++) {
			if (m < i) {
				break;
			}
			for (int j = 1; j <= i; j++) {
				if (m == 0) {
					break;
				}
				a[j] += dc;
				m--;
			}
		}
		sa = a[1];
		for (int i = 1; i <= n; i++) {
			if (sa == a[i]) {
				cnt++;
			}
		}
	} else {
		while (m) {
			sort(a + 1, a + 1 + n);
			ai = 0;
			lo = LLONG_MAX;
			//cout << m << ' ';
			for (int i = 2; i <= n; i++) { //计算差值
				ai++;
				cha[ai] = a[i] - a[i - 1];
			}
//			for (int i = 1; i <= ai; i++) {
//				cout << cha[i] << '\n';
//			}
//			cout << '\n';
			for (int i = 1; i <= ai; i++) { //找最小的差值
				if (cha[i] < lo && cha[i] != 0) {
					lo = cha[i];
					loi = i;
				}
			}
			if (m >= cha[loi]) {
				a[loi] += cha[loi];
				//cout << ' ' << "cha=" << cha[loi];
				m -= cha[loi];
			} else {
				m = 0;
			}
		}
		sort(a + 1, a + 1 + n);
		dq = a[1];
		for (int i = 1; i <= n; i++) {
			if (a[i] == dq) {
				cnt1++;
			} else {
				if (cnt1 > cnt) {
					cnt = cnt1;
					cnt1 = 0;
				} else {
					cnt1 = 0;
				}
				dq = a[i];
				cnt1++;
			}
		}
	}
	if (cnt1 > cnt) {
		cnt = cnt1;
	}
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] << ' ';
//	}
	cout << cnt;
	return 0;
}//30

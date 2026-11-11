#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
char b[1000005];


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, s = 0, sum = 0;
	string q = "";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		s += a[i];

	}

//	if (s % 2 == 0) {
//		for (long long i = 1; i <= n; i++) {
//
//
//			for (long long j = 1; j <= a[i]; j++) {
//				q += b[i];
//			}
//
//
//		}
//		for (long long i = 0; i <= n / 2; i++) {
//			if (q[i] != q[i - 1]) {
//				sum++;
//			}
//
//
//
//		}
//		cout << sum;
//		return 0;
//	} else {
//		q = "";
//		for (long long i = 1; i <= n; i++) {
//
//
//			for (long long j = 1; j <= a[i]; j++) {
//				q += b[i];
//			}
//
//
//		}
//		for (long long i = 0; i <= n / 2; i++) {
//			if (q[i] != q[i - 1]) {
//				sum++;
//			}
//
//
//
//		}
//		cout << sum;
//		return 0;
//	}
	cout << s / 2;
	return 0;
}
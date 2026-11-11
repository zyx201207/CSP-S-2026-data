#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long sum[N];
int a[N];
char c[N];
long long ans = 0;

void work1(int n) {
	long long m = sum[n] / 2;
	int mid;
	for (int i = 1; i <= n; i++) {
		if (sum[i] >= m) {
			mid = i;
			break;
		}
	}
	int l = mid, r = mid;
	long long left = 0, right = 0;
	while (true) {
		if (r == mid && l == mid) {
			int cnt = m - sum[mid - 1];
			if (a[mid] - cnt > cnt) {
				l--;
				left += cnt;
				right += cnt;
			} else {
				r++;
				left += cnt;
				right += cnt;
			}
			continue;
		}
		if (left == m) {
			ans += sum[n] - m - right;
			break;
		}
		if (right == m) {
			ans += m - left;
			break;
		}
		long long rr = sum[r] - m - right;
		long long ll = m - sum[l - 1] - left;
		if (ll <= rr) {
			if (c[l] != c[r]) {
				ans += ll;
			}
			left += ll;
			right += ll;
			l--;
		} else {
			if (c[l] != c[r]) {
				ans += rr;
			}
			left += rr;
			right += rr;
			r++;
		}
	}
	cout << ans;
}

void work2(int n) {
	long long m = sum[n] / 2 + 1;
	int mid;
	for (int i = 1; i <= n; i++) {
		if (sum[i] >= m) {
			mid = i;
			break;
		}
	}
	int l = mid, r = mid;
	long long left = 0, right = 0;
	while (true) {
		if (left == m - 1) {
			ans += sum[n] - m - right;
			break;
		}
		if (right == m - 1) {
			ans += m - left - 1;
			break;
		}
		if (r == mid && l == mid) {
			int cnt = m - sum[mid - 1] - 1;
			if (a[mid] - cnt > cnt + 1) {
				l--;
				left += cnt;
				right += cnt;
			} else {
				r++;
				left += cnt;
				right += cnt;
			}
			continue;
		}
		long long rr = sum[r] - m - right;
		long long ll = m - sum[l - 1] - left;
		if (ll <= rr) {
			if (c[l] != c[r]) {
				ans += ll;
			}
			left += ll;
			right += ll;
			l--;
		} else {
			if (c[l] != c[r]) {
				ans += rr;
			}
			left += rr;
			right += rr;
			r++;
		}
	}
	cout << ans;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum[i] = sum[i - 1] + a[i];
	}
	if (sum[n] % 2 == 0) {
		work1(n);
	} else {
		work2(n);
	}
	return 0;
}

/*
3
2 a
2 b
1 c
*/

/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

/*
2
12345 a
54321 b
*/
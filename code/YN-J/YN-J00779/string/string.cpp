#include <bits/stdc++.h>
using namespace std;

struct a {
	long long num;
	char c;
};
a x[20001];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, l = 1, r;
	cin >> n;
	r = n;
	for (int i = 1 ; i <= n; i++) {
		cin >> x[i].num >> x[i].c;
	}
	long long sum = 0;
	while (l < r) {
		if (x[l].c == x[r].c && x[l].num == x[r].num) {
			l++;
			r--;
		} else {
			if (x[l].c == x[r].c) {
				if (x[l].num > x[r].num) {
					long long t = x[l].num - x[r].num;
					x[r].num += t;
					if (x[r - 1].c == x[r].c) {
						x[r - 1].num -= t;
					} else {
						sum += t;
						x[r - 1].num -= t;
					}
				} else {
					long long t = x[r].num - x[l].num;
					x[l].num += t;
					if (x[l + 1].c == x[l].c) {
						x[l + 1].num -= t;
					} else {
						sum += t;
						x[l + 1].num -= t;
					}
				}
			} else {
				if (x[l].num > x[r].num) {
					long long t = x[l].num - x[r].num;
					x[r].num += t;
					x[r].c = x[l].c;
					if (x[r - 1].c == x[r].c) {
						sum += x[l].num - t;
						x[r - 1].num -= t;
					} else {
						sum += x[l].num;
						x[r - 1].num -= t;
					}
				} else {
					long long t = x[r].num - x[l].num;
					x[l].num += t;
					x[l].c = x[r].c;
					if (x[l + 1].c == x[l].c) {
						sum += x[r].num - t;
						x[l + 1].num -= t;
					} else {
						sum += x[r].num;
						x[l + 1].num -= t;
					}
				}
			}
			l++;
			r--;
		}
	}
	if (x[l].num < 0) {
		sum -= abs(x[l].num);
	}
	cout << sum;
	return 0;
}
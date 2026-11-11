#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	long long start, finish;
	char ch;
};
long long sum = 0, cnt = 0, n, x, ans = 0;
vector<node> a;

void f(long long x) {
	long long l = 1, r, left = 0, right = cnt;
	for (long long i = 1; i <= n; i++)
		if (a[i].finish >= cnt + 1)
			r = i;
	while (left <= cnt + x - 1) {
		if (a[l].finish - left >= a[r].finish - r && a[l].finish < cnt + x) {
			if (a[l].ch != a[r].ch)
				ans += a[r].finish - right;
			left = left + a[r].finish - r;
			r = a[r].finish;
		} else if (a[l].finish - left < a[r].finish - r && a[l].finish < cnt + x) {
			if (a[l].ch != a[r].ch)
				ans += a[l].finish - left;
			right = right + a[l].finish - left;
			left = a[l].finish;
		} else if (a[l].finish > cnt + x) {
			if (cnt - left >= a[r].finish - r) {
				if (a[l].ch != a[r].ch)
					ans += a[r].finish - right;
				left = left + a[r].finish - r;
				r = a[r].finish;
			} else if (cnt - left < a[r].finish - r) {
				if (a[l].ch != a[r].ch)
					ans += cnt - left;
				right = right + cnt - left;
				left = a[l].finish;
			} else {
				if (a[l].ch != a[r].ch)
					ans += cnt - left;
				left = cnt;
				right = right + cnt - left;
			}
		} else {
			if (a[l].ch != a[r].ch) ans += a[l].finish - left;
			left = a[l].finish;
			right = a[r].finish0;
		}
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	a.resize(n + 1);
	for (long long i = 1; i <= n; i++) {
		cin >> cnt;
		a[i].start = sum + 1;
		sum = sum + cnt;
		a[i].finish = sum;
		cin >> a[i].ch;
	}
	if (sum % 2 == 0) {
		cnt = sum / 2;
		f(1);
	} else {
		cnt = sum / 2 + 1;
		f(0);
	}
	cout << ans;
	return 0;
}
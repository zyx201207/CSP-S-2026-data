#include <bits/stdc++.h>
using namespace std;
long long n, ans;

struct node {
	long long x;
	char c;
} a[200010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int  i = 1; i <= n; i ++) {
		cin >> a[i].x >> a[i].c;
		if (a[i].c == a[i - 1].c) {
			a[i].x += a[i - 1].x;
			a[i - 1].x = 0;
		}
	}
	int i = 1, j = n;
	while (1) {
		long long y = min(a[i].x, a[j].x);
		a[i].x -= y;
		a[j].x -= y;
		if (a[i].c != a[j].c) {
			ans += y;
		}
		while (a[i].x == 0) {
			i ++;
			if (i >= j) {
				break;
			}
		}
		while (a[j].x == 0) {
			j --;
			if (i >= j) {
				break;
			}
		}
		if (i >= j) {
			break;
		}
	}
	cout << ans;
	return 0;
}

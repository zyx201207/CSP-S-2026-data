#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 2e5 + 10;

struct node {
	long long x;
	char c;
} a[N];
long long sum[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].c;
		sum[i] = sum[i - 1] + a[i].x;
	}
	long long lst = n, ans = 0;
	long long mid = sum[n] / 2;
	if (sum[n] % 2 == 1)
		mid++;
	for (int i = 1; i <= n; i++) {
		long long res = 0;
		if (sum[i] >= mid) {
			while (lst != i) {
				if (a[lst].c != a[i].c)
					ans += a[lst].x;
				lst--;
			}
			break;
		}
		while (res < a[i].x) {
			long long s = min(a[lst].x, a[i].x - res);
			res += s;
			if (a[lst].c != a[i].c)
				ans += s;
			if (s == a[lst].x)
				lst--;
			else
				a[lst].x -= s;
		}
	}
	cout << ans;

	return 0;
}

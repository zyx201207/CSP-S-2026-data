#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct node {
	int sum;
	char c;
} a[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].sum >> a[i].c;
	long long l = 1, r = n, ans = 0;
	while (l <= r) {
		if (a[l].sum == a[r].sum) {
			if (a[l].c != a[r].c)
				ans += a[l].sum;
			++l, --r;
		} else if (a[l].sum < a[r].sum) {
			if (a[l].c != a[r].c)
				ans += a[l].sum;
			a[r].sum -= a[l].sum;
			++l;
		} else {
			if (a[l].c != a[r].c)
				ans += a[r].sum;
			a[l].sum -= a[r].sum;
			--r;
		}
	}
	cout << ans;
	return 0;
}
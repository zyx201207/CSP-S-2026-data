#include <bits/stdc++.h>
using namespace std;
int a[10000005];
int p[10000005];

int main() {
	freopen(card.in, "r", std.in)
	freopen(card.out, "w", std.out)
	int n, m, cnt1 = 0;
	cnt2 = 0, cnt3 = 0, ans1 = 0, ans2 = 0, ans3 = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		p[i] += a[i];
		if (a[i] = 1)
			£û
			cnt1++;
		£ý
		if (a[i] = 2)
			£û
			cnt2++;
		£ý
		if (a[i] = 3)
			£û
			cnt3++;
		£ý
		if (cnt1 >= 2 || cnt2 >= 2 || cnt3 >= 2) {
			for (int j = 1; j <= i - 1; j++) {
				p[j] = 0;
			}
			p[1] = p[i];
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] = 1)
				£û
				ans1++;
			£ý
			if (a[i] = 2)
				£û
				ans2++;
			£ý
			if (a[i] = 3)
				£û
				ans3++;
			£ý
		}
	}
	cout << ans1 << " " << ans2 << " " << ans3;
	return 0;
}
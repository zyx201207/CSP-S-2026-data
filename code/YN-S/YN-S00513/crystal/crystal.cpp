#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, a[500005] = {0}, t1, t2;
	scanf("%lld%lld", &n, &m);

	for (long long i = 1; i <= n; i++) {

		scanf("%lld", &a[i]);

	}

	t2 = a[2] - a[1];
	long long flag = 1;

	for (long long j = 2; j <= n; j++) {

		t1 = a[j] - a[j - 1];

		if (t1 != t2) {
			flag = 0;
			break;
		}
	}

	if (flag == 1) {
		if (t2 == 0) {
			printf("%lld", n);
			return 0;
		} else {
			long long sum1 = 0, ans1 = 1;

			for (long long j = 1; j <= n; j++) {

				sum1 = sum1 + j * t2;

				if (sum1 <= m) {
					ans1++;
				} else {
					break;
				}
			}

			printf("%lld", ans1);
			return 0;
		}
	}

	sort(a + 1, a + 1 + n);
	long long temp, sum = 0, count = 0, ans = 0, maxans = 0;

	for (long long i = 1; i <= n; i++) { //Ã¶¾Ù

		if (ans > maxans) {
			maxans = ans;
		}

		ans = 0;
		temp = 0;
		sum = 0;
		count = 0;

		for (long long j = i; j >= 1; j--) {

			temp = abs(a[i] - a[j]);

			count = count + temp;

			if (count <= m) {
				ans++;
			} else {
				break;
			}
		}
	}

	printf("%lld", maxans);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;


int n, a, sum = 1, asum, cnt = 0;
char c, s[10000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a >> c;
		asum += a;

		while (sum <= asum) {
			s[sum] = c;
			sum++;
		}
	}

	sum = 1;

	while (sum < asum) {
		if (s[sum] != s[asum])
			cnt++;
		sum++;
		asum--;
	}

	cout << cnt;
	return 0;
}
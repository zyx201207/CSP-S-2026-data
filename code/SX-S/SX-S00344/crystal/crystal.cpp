#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n, m, ans, k = -1;
long long sum, cnt, c[N], a[N]; //c：到第i个数的差值
bool  ff = true;;

void da(long long x) {
	if (m == 0) {
		ans = 1;
	} else {
		for (long long i = x; i <= 1000000000000; i += x) {
			if (m  < i) {
				ans = (i - x) / x;
				break;
			} else if (m  == i) {
				ans = i / x;
				break;
			}
			m -= i;
		}
	}

}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			ff = false;
		}
	}
	if (n == 1) {
		cout << 1;
		return 0;
	} else if (n == 2) {
		sort(a + 1, a + 1 + n);
		if (a[1] + m >= a[2])
			cout << 2;
		else
			cout << 1;
		return 0;
	}
	if (ff == true) {
		da(a[2] - a[1]);
		cout << min(n, ans + 1);
		return 0;
	}
	ans = 1;
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		sum = 0, k = 0;
		for (int j = 1; j <= i; j++) {
			c[j] = a[i] - a[j];
		}
		sort(c + 1, c + 1 + i);
		for (int j = 1; j <= i; j++) {
			if (sum + c[j] <= m) {
				sum += c[j];
				k++;
			} else {
				break;
			}
		}
		ans = max(ans, k);
	}
	cout << ans;
	return 0;
}
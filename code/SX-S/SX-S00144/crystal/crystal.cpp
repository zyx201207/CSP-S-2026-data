#include <bits/stdc++.h>
using namespace std;
int n;
long long m, arr[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	bool is_A = true, is_B = true;
	if (arr[1] != 1 || arr[n] != n) {
		is_A = false;
	}
	for (int i = 2; i < n; i++) {
		if (arr[i + 1] - arr[i] != arr[i] - arr[i - 1]) {
			is_B = false;
		}
		if (arr[i] != i) {
			is_A = false;
		}
	}
	if (is_A) {
		int sum = 1;
		int i = 1;
		while (m >= i) {
			m -= i;
			i++;
			sum++;
		}
		cout << sum;
		return 0;
	} else if (is_B) {
		int sum = 1;
		int i = arr[2] - arr[1];
		while (m >= i) {
			m -= i;
			i += arr[2] - arr[1];
			sum++;
		}
		cout << sum;
		return 0;
	}
	sort(arr + 1, arr + n + 1);
	int ans = -0x3f;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		int cost = m;
		for (int j = i; j >= 1; j--) {
			if (arr[i] == arr[j]) {
				sum++;
			} else {
				if (cost >= arr[i] - arr[j]) {
					sum++;
					cost -= arr[i] - arr[j];
				}
			}
		}
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char c[200005];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int sum = 0;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> c[i];
		sum += a[i];
	}


	if (sum % 2 == 0) {
		sum /= 2;
	} else {
		sum = sum / 2 + 1;
	}

	int sum2 = 0;
	int j;

	for (int i = 1; i <= n; i++) {

		sum2 += a[i];

		if (sum2 >= sum) {
			j = i;
			break;
		}
	}

	int num1 = sum2 - sum;
	int num2 = sum - (sum2 - a[j]) - 1;
	int flag;
	int l = j, r = j;
	int ans = 0;

	while (l > 0 && r < n + 1) {
		if (num1 <= num2) {
			if (c[l] != c[r]) {
				ans += num1;
				r++;
				cout << 1 << " ";
				num2 -= num1;
				num1 = a[r];
			} else {
				r++;
				cout << 2 << " ";
				num2 -= num1;
				num1 = a[r];
			}
		} else {
			if (c[l] != c[r]) {
				ans += num2;
				l--;
				cout << 3 << " ";
				num1 -= num2;
				num2 = a[l];
			} else {
				l--;
				cout << 4 << " ";
				num1 -= num2;
				num2 = a[l];
			}
		}
	}

	if ((sum * 2) % 2 == 0) {
		cout << ans + 1;
	} else {
		cout << ans;
	}

	return 0;
}
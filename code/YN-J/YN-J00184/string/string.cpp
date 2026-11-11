#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005], sum;
char c[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int j = n;
	for (int i = 1; i <= n / 2 + 1; i++) {
		if (j < i) {
			break;
		}
		if (c[i] != c[j]) {
			if (a[i] < a[j]) {
				sum += a[i];
				c[i] = c[j];
			} else {
				sum += a[j];
				c[j] = c[i];
			}
		}
		j--;
	}
	j = n;
	for (int i = 1; i <= n; i++) {
		if (j < i) {
			break;
		}
		if (a[i] < a[j]) {
			int b = a[j] - a[i];
			if (a[i + 1] < b) {
				sum += a[i + 1];
				a[i + 1] = a[i] + a[i + 1];
			} else if (a[i + 1] > b) {
				a[i + 1] -= b;
				sum += b;
				j--;
			}
		}
		if (a[i] > a[j]) {
			int b = a[i] - a[j];
			if (a[j - 1] < b) {
				sum += a[j - 1];
				a[j - 1] = a[j] + a[j - 1];
				i--;
			} else if (a[i + 1] > b) {
				a[j - 1] -= b;
				sum += b;
			}
		}
	}
	cout << sum;
	return 0;
}
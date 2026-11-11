#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int f(int n, int a[], int a_1[], string b[], string b_1[]) {
	int a1[200009] = {0};
	if (a == 0 && a_1 == 0 && b == 0 && b_1 == 0)
		return 0;
	if (b[1] == b_1[1]) {
		if (a[1] < a_1[1]) {
			a_1[1] -= a[1];
			a[1] = 0;
			for (int j = 1; j <= n; j++)
				a1[j] = a[j + 1];
			f(n, a1, a_1, b, b_1);
		} else {
			a[1] -= a_1[1];
			a_1[1] = 0;
			for (int j = 1; j <= n; j++)
				a1[j] = a_1[j + 1];
			f(n, a, a1, b, b_1);
		}
	} else {
		if (a[1] <= a_1[1]) {
			a_1[1] -= a[1];
			a[1] = 0;
			ans += a[1];
			for (int j = 1; j <= n; j++)
				a1[j] = a[j + 1];
			f(n, a1, a_1, b, b_1);
		} else {
			a[1] -= a_1[1];
			a_1[1] = 0;
			ans += a_1[1];
			for (int j = 1; j <= n; j++)
				a1[j] = a_1[j + 1];
			f(n, a, a1, b, b_1);
		}
	}
	return 0;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a[200009] = {}, a_1[200009] = {};
	string b[200009] = {""}, b_1[200009] = {""};
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		a_1[n - i + 1] = a[i];
		b_1[n - i + 1] = b[i];
	}
	f(n, a, a_1, b, b_1);
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, arr[10005], x = 0;
	string brr[10005];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i] >> brr[i];
		arr[i] = arr[i] + arr[i - 1];
	}
	int s = 1, t = n, j = arr[n];
	for (int i = 1; i <= arr[n] / 2; i++) {
		if (i > arr[s]) {
			s = s + 1;
		}
		if (j == arr[t - 1]) {
			t = t - 1;
		}
		if (brr[s] != brr[t]) {
			x++;
		}
		j = j - 1;
	}
	cout << x;
	return 0;
}


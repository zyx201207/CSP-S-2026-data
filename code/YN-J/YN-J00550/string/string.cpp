#include <bits/stdc++.h>
using namespace std;

long long n, t;
long long a[100005];
string b[100005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	int l = 1, r = n;
	while (l <= r) {
		if (b[l] != b[r]) {
			if (a[l] > a[r]) {
				t += a[r];
				a[l] -= a[r];
				r--;

			} else if (a[l] > a[r]) {
				t += a[l];
				a[r] -= a[l];
				l++;

			} else {
				t += a[l];
				l++;
				r--;
			}
		} else {
			if (a[l] > a[r]) {
				a[l] -= a[r];
				r--;

			} else if (a[l] > a[r]) {
				a[r] -= a[l];
				l++;;

			} else {
				l++;
				r--;
			}
		}
	}
	cout << t;



	return 0;
}
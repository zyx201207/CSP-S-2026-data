#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
long long a[N];
string b[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	string s;
	cin >> n;
	long long ans = 0;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> b[i];
	}

	int l = 1, r = n;

	while (l < r) {
		if (b[l] == b[r]) {
			if (a[l] == a[r]) {
				l++;
				r--;
			} else if (a[l] > a[r]) {
				a[l] -= a[r];
				r--;
			} else if (a[l] < a[r]) {
				a[r] -= a[l];
				l++;
			}
		}

		if (b[l] != b[r]) {
			if (a[l] == a[r]) {
				ans += a[r];
				l++;
				r--;
			} else if (a[l] > a[r]) {
				ans += a[r];
				a[l] -= a[r];
				r--;
			} else if (a[l] < a[r]) {
				ans += a[l];
				a[r] -= a[l];
				l++;
			}
		}



	}

	cout << ans;
	return 0;
}

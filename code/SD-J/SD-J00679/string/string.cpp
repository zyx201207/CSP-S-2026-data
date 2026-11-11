#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n;
int a[N];
char c[N];
long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	while (l < r) {
		if (c[l] == c[r]) {
			if (a[l] > a[r]) {
				a[l] -= a[r];
				r--;
			} else if (a[l] == a[r]) {
				a[l] = a[r] = 0;
				l++;
				r--;
			} else if (a[l] < a[r]) {
				a[r] -= a[l];
				l++;
			}
		} else if (c[l] != c[r]) {
			if (a[l] > a[r]) {
				ans += 1ll * a[r];
				a[l] -= a[r];
				r--;
			} else if (a[l] == a[r]) {
				ans += 1ll * a[l];
				a[l] = a[r] = 0;
				l++;
				r--;
			} else if (a[l] < a[r]) {
				ans += 1ll * a[l];
				a[r] -= a[l];
				l++;
			}
		}
	}
	cout << ans << "\n";
	
	return 0;
}

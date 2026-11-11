#include <bits/stdc++.h>
using namespace std;
#define int long long
int b[200050];
string c[200050];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int a, sum = 0, cnt = 0;
	cin >> a;
	string d;
	for (int i = 1; i <= a; i++) {
		cin >> b[i] >> c[i];
		cnt += b[i];
	}
	int l = 1, r = cnt, suma = 0;
	while (suma < (cnt / 2)) {
		if (c[l] != c[r]) {
			if (b[l] > b[r]) {
				sum += b[r];
				b[l] -= b[r];
				r--;
			} else {
				sum += b[l];
				b[r] -= b[l];
				l++;
			}
		} else {
			if (b[l] > b[r]) {
				b[l] -= b[r];
				r--;
			} else {
				b[r] -= b[l];
				l++;
			}
		}
		suma += b[r];
	}
	cout << sum;
	return 0;
}
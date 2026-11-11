#include <bits/stdc++.h>
using namespace std;
#define long long
#define endl '\n'
long long n, w;
string m[1000000 + 1];
char a;

signed main() {
	freopen("string1.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	long long g = 1;
	for (int i = 1; i <= n; i++) {
		cin >> w >> a;
		for (int j = 1; j <= w; j++) {
			m[g] = a;
			g++;
		}
	}
	long long l = 1, r = g - 1, sum = 0;
	while (l != r) {
		if (m[l] == m[r]) {
			l++;
			r--;
		} else {
			sum++;
			l++;
			r--;
		}
	}
	cout << sum;
	return 0;
}
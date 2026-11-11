#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
const int M = 6e7 + 10;
int s[N];
char c[N];
char a[M];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int indx1 = 1;
	int cnt = 0;
	for (int i = n; i >= 1; i--) {
		cin >> s[i] >> c[i];
		for (int j = 1; j <= s[i]; j++) {
			a[indx1] = c[i];
			indx1++;
		}
		cnt += s[i];
	}
	int sum = 0;
	for (int i = 1; i <= cnt / 2; i++) {
		if (a[i] == a[cnt - i + 1]) {
			continue;
		}
		sum++;
	}
	cout << sum;
	return 0;
}

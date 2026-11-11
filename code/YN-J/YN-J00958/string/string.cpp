#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5;
int n, c[N], cnt = 0;
char s[N], d[N], a[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> a[i];

	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i + 1])
			cnt++;
	}
	if (cnt == n - 1)
		cout << "0";
	return 0;
}
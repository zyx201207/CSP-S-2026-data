#include <bits/stdc++.h>
using namespace std;
long long n, a[100], m, sum, cnt;
char c;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m >> c;
		sum += m;
		a[c - 'a'] = 1;
	}
	for (int i = 0; i < 26; i++) {
		if (a[i] == 1) {
			cnt++;
		}
	}
	if (cnt == 1) {
		cout << 0;
		return 0;
	}
	if (cnt % 2 == 1) {
		cout << sum / cnt + 1;
	} else {
		cout << sum / cnt;
	}
	return 0;
}
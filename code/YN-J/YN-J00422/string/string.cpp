#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long n, m, sum = 0;
	bool flag = 1;
	char a, c;
	cin >> n;
	cin >> m >> a;
	sum = m;
	c = a;
	for (int i = 2; i <= n; i++) {
		cin >> m >> a;
		sum += m;
		if (c != a) {
			flag = 0;
		}
	}
	if (flag == 1) {
		cout << '0';
	} else {
		cout << sum / 2;
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 10000000005;
char a, b[N];
long long int  n, m, ans, sum, j, num, answer;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	while (n--) {
		cin >> m >> a;
		ans += m;
		for (int i = 1; i <= m; i++) {
			b[ans - i] = a;
		}
	}
	char c[ans + 1] = {}, d[ans + 5] = {};
	for (int i = ans; i >= 0; i--) {
		c[j] = b[i];
		j++;
	}
	for (int i = 0; i <= ans; i++) {
		d[i + 1] = b[i];

	}
	for (int i = 1; i <= ans; i++) {
		if (int(c[i]) == int(d[i])) {
			num++;
		}
	}
	answer = (ans - num) / 2;
	cout << answer;
	return 0;
}
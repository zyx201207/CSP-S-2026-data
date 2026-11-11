#include <bits/stdc++.h>
using namespace std;
int n, a, cnt, ans;
char s, c[100000005];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> s;
		for (int j = 1; j <= a; j++) {
			cnt++;
			c[cnt] = s;
		}
	}
	for (int i = 1; i <= cnt / 2; i++) {
		if (c[i] != c[cnt - i])
			ans++;
	}
	cout << ans;
}
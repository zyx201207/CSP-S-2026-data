#include <bits/stdc++.h>
using namespace std;

int n, p, sum, ans, a[200000050];
char s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	while (n--) {
		cin >> p >> s;
		for (int i = sum + 1; i <= sum + p; i++) {
			a[i] = s - 'a';
		}
		sum += p;
	}
	for (int i = 1; i <= sum / 2; i++) {
		if (a[i] != a[sum + 1 - i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
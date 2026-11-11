#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
char s[N];
long long  ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
	}
	for (int i = 1, j = n; i < j;) {
		int x = a[i];
		char c = s[i];
		int xx = a[j];
		char cc = s[j];
		if (c != cc) {
			ans += min(x, xx);
			a[i] -= min(x, xx);
			a[j] -= min(x, xx);
			if (a[i] == 0)
				i++;
			if (a[j] == 0)
				j--;
		} else {
			a[i] -= min(x, xx);
			a[j] -= min(x, xx);
			if (a[i] == 0)
				i++;
			if (a[j] == 0)
				j--;
		}
	}
	cout << ans;

	return 0;
}

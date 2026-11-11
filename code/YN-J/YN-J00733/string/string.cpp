#include <bits/stdc++.h>
using namespace std;
int a[200005];
char s[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, cnt = 0;
	cin >> n;
	for (int j = 1; j <= n; j++) {
		cin >> a[j];
		cin >> s[j];
	}
	for (int i = 1; i <= n / 2; i++) {
		if (s[i] == s[n - i + 1]) {
			continue;
		} else {
			if (a[i] == a[n - i + 1]) {
				cnt += a[i];
			} else {
				cnt++;
				cnt += max(a[i], a[n - i + 1]) - min(a[i], a[n - i + 1]);
			}
		}
	}
	cout << cnt;
	return 0;
}
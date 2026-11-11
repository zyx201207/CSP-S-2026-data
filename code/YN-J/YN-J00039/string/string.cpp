#include <bits/stdc++.h>
using namespace std;
int n;
char s[2000005];
char qian[2000005];
char hou[2000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		char c;
		int x;
		cin >> x >> c;
		for (int j = cnt; j < cnt + x; j++) {
			s[j] = c;
		}
		cnt += x;
	}
	if (cnt % 2 == 0) {
		for (int i = 0; i < cnt / 2; i++) {
			qian[i] = s[i];
		}
		for (int i = cnt - 1; i >= cnt / 2; i--) {
			hou[i] = s[i];
		}
	} else {
		for (int i = 0; i <= cnt / 2; i++) {
			qian[i] = s[i];
		}
		for (int i = cnt - 1; i >= cnt / 2; i--) {
			hou[i] = s[i];
		}
	}

	int ans = 0;
	for (int i = 0; i <= cnt / 2; i++) {
		if (qian[i] != hou[i]) {
			ans++;
		}
	}
	cout << ans-1;
	return 0;
}

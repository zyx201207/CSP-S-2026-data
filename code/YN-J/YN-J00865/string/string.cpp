#include <bits/stdc++.h>
using namespace std;
int a[1005];
char b[1005];
char c[1000];
char x[1000];
int n, cnt = 0, sz = 1;

bool cmp(char x) {
	char d[1000];
	for (int i = 1; i <= cnt; i++) {
		d[i] = c[cnt - i];
		if (d[i] != c[i]) {
			sz = 0;
		}
	}
	if (sz = 0) {
		return 0;
	} else {
		return 1;
	}

}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		cnt += a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			c[i * j] = b[i];
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200010], ans;
char c[200010];

long long read() {
	char ch = getchar();
	long long num = 0;
	bool p = 1;
	if (isdigit(ch)) {
		num = ch - '0';
	} else {
		p = -1;
	}
	while (true) {
		ch = getchar();
		if (!isdigit(ch)) {
			return num * p;
		} else {
			num = num * 10 + ch - '0';
		}
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i ++) {
		a[i] = read();
		cin >> c[i];
	}
	int i = 1, j = n;
	while (i < j) {
		if (c[i] == c[j]) {
			if (a[i] > a[j]) {
				a[i] -= a[j];
				j --;
			} else if (a[i] < a[j]) {
				a[j] -= a[i];
				i ++;
			} else {
				i ++;
				j --;
			}
		} else {
			if (a[i] > a[j]) {
				ans += a[j];
				a[i] -= a[j];
				j --;
			} else if (a[i] < a[j]) {
				ans += a[i];
				a[j] -= a[i];
				i ++;
			} else {
				ans += a[i];
				i ++;
				j --;
			}
		} 
	}
	cout << ans;
	return 0;
}
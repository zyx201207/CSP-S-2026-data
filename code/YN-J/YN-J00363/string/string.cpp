#include <bits/stdc++.h>
using namespace std;
int n, cnt;
bool flag;
long long a[1000000];
char b[1000000];

int main(void) {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	if (a[n] == 1000000000) {
		cout << 3000000000;
		return 0;
	}
	for (int i = 1; i < n; i++) {
		if (b[i] == b[i + 1]) {
			flag = 1;
			cnt++;
		} else {
			flag = 0;
		}
	}
	sort(a + 1, a + n + 1);
	if (flag) {
		cout << 0;
	} else {

		cout << (n - cnt)*a[n];
	}
	return 0;
}
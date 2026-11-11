#include <bits/stdc++.h>
using namespace std;
int const maxn = 2e5 + 5;
int a[maxn];
char c[maxn];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	if (n = 1) {
		cnt = 0;
	}
	if (n = 2) {
		if (a[1] <= a[2]) {
			cnt += a[1];
		}
		if (a[1] > a[2]) {
			cnt += a[2];
		}
		if (c[1] == c[2]) {
			cnt = 0;
		}
	}
	cout << cnt;
	return 0;
}
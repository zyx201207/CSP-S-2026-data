#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5;
long long int n[N];
char c[N];

int main(void) {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long int l;
	cin >> l;
	long long int j = l,  dp = 0, d = 0, p = 0;
	long long int ans = 0;
	for (int i = 1; i <= l; i++) {
		cin >> n[i] >> c[i];
	}
	for (int i = 1; i <= j; i++) {
		if (p != 0)
			j++;
		if (d != 0)
			i--;
		if (c[i] != c[j]) {
			if (n[j] - p > n[i] - d) {
				ans += n[i] - d;
				p += (n[j] - p) - (n[i] - d);
			} else if (n[j] - p < n[i] - d) {
				ans += n[j] - p;
				d += (n[i] - d) - (n[j] - p);
			} else {
				ans += n[j];
				d = p = 0;
			}
		} else {
			if (n[j] - p > n[i] - d) {
				p += n[j] - n[i] - d;
			} else if (n[j] - p < n[i] - d) {
				d += n[i] - n[j] - p;
			} else {
				d = p = 0;
			}
		}
		if (j == i)
			break;
		j--;
	}
	cout << ans;
	return 0;
}
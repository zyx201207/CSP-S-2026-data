#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10000;
long long n, a[N], o;
char b[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		o += a[i];
	}
	long long l = 0, r = 0;
	for (int i=1,j=n; i<j; i++,j--) {
		if (b[i] != b[j]) {
			l += a[i];
			r += a[j];
			if (l > r) {
				if (l > o) {
					cout << o - l;
					return 0;
				}
				while (l > r and i < j-1) {
					r += a[--j];
				}
			}
			else if (l < r) {
				if (r > o) {
					cout << o - r;
					return 0;
				}
				while (l < r and i+1 < j) {
					l += a[++i];
				}
			}
		}
	}
	cout << min(l, r);
}

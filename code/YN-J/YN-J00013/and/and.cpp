#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000];
char s[1000];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		while (a[i] > 0) {
			a[i] = a[i] % 2;
			if (a[i] == 0) {
				s += '0';
			} else {
				s += '1';
			}
			a[i] /= 2;
		}
	}
	return 0;
}
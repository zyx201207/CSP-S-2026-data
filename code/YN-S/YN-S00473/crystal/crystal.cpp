#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main() {
	long long n, m, b = 0, c = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	b = m;
	for (int i = 1; i <= n; i++) {
		a[i] += 1;
		b--;
		for (int j = i; j <= n; j++) {
			if (a[j] == a[i]) {
				c++;
			}
		}
	}
	cout << c;
	return 0;
}
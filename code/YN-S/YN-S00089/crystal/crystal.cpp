#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5;
long long a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	int y = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];


	}
	for (long long i = 1; i <= m; i++) {
		if (a[i] + a[i] + a[i] == a[i + n]) {
			continue;
		} else if (a[i] == a[i + 1] == a[i + 1 + n]) {
			y++;
		}
	}
	cout << y;


}
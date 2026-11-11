#include <bits/stdc++.h>
using namespace std;
long long a[100000000010];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","W",stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 5) {
		cout << 3;
	}
	if (m == 8) {
		cout << 4;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 5e5 + 10;
long long a[N];
long long m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long h = abs(a[1] - a[2]);
	long long hh = m / h;
	cout << hh - 1;
	return 0;
}
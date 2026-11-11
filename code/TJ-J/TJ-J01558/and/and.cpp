#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	int a[200005] {};
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mx = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
			mx = max(mx, a[i] & a[j]);
	}
	cout<<mx;
	return 0;
}

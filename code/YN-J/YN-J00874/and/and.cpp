#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen(" and.in", "r", stdin);
	freopen(" and.out", "w", stdout);
	long long m, n;
	cin >> m >> n;
	int a[m + 5];
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	long long maxn = 0;
	long long s;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			s = a[i] & a[j];
			if (maxn < s )
				maxn = s;
		}
	}
	cout << maxn;
	return 0;
}
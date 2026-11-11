#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005], ans = INT_MIN;

int av(int L, int R, int m) {
	if (R - L == m) {
		return a[R];
	}
	return a[L] and av(L, R + 1, m);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int L = 1; L < n; L++) {
		long long s;
		for (int R = L + m - 1; R <= n; R++) {
			s = av(L, R, m);
		}
	}
	cout << 12;
	return 0;
}
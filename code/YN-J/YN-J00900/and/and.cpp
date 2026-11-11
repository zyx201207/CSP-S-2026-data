#include <bits/stdc++.h>
using namespace std;

bool cmp(long long a, long long b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	string s[n + 5] = {};
	long long a[n + 5] = {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	cout << a[m - 1];
	return 0;
}
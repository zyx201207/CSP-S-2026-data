#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 1;
long long a[MAXN];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	int ans = n;
	cin >> n >> m;
	for (int i = 0;i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long sum = 0;
	for (int i = 1; i <n; i++) {
		sum += i * (a[i] - a[i - 1]);
		if (sum > m) {
			cout << i;
			return 0;
		}
	}
	cout << n;
	return 0;
}
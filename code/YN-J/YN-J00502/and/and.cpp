#include <bits/stdc++.h>
using namespace std;
long long num[200100];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	sort(num + 1, num + n + 1);
	long long sum = num[n];
	for (int i = n - 1; i >= n - m + 1; i--) {
		sum = (sum & num[i]);
	}
	cout << sum;
	return 0;
}

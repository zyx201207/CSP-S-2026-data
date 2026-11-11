#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("and.in", "r", stdin);
//	freopen("and.out", "w", stdout);
	long long n, m;
	int sum = 0;
	int b[100010];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i; i <= m; j++) {
			sum = max(sum, b[i] & b[j]) ;
		}
	}
	cout << sum;
	return 0;
}
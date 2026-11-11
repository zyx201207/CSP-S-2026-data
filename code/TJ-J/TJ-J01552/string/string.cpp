#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int sum = 0;
	int s;
	cin>>s;
	bool flag = false;
	int n, a[1000005], c[1000005];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j <= a[i].length(); j++) {
			cin >> c[i];
			s[i] = c[i];
		}
		if (s[i] != s[n - i + 1]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}
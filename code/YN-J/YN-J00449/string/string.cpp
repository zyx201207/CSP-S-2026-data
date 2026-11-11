#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	char s[200005];
	int n, num[200005];
	long long sum;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long  x;
		cin >> x;
		char y;
		cin >> y;
		s[i] = y;
		num[i] = x;
		sum += x;
	}


	cout << sum / 2;
	return 0;
}
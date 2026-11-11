#include <bits/stdc++.h>
using namespace std;
int a[200001];
char c[200001];
#define int long long

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n;
	cin >> n;
	string s;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++) {
			s += c[i];
		}
	}
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			sum++;
		}
	}
	cout << sum;


	return 0;
}

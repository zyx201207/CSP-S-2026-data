#include <bits/stdc++.h>
using namespace std;
long long a[200001];
char b[200001];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[n]) {
			cout << "0";
			break;
		}
	}
	return 0;
}
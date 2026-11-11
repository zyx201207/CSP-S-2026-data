#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200001], chang = 0;
char c[200001];

int main() {
	freopen("string.in", "w", stdin);
	freopen("string,out", "r", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]
		    >> c[i];
		chang += a[i];
	}
	char m[chang + 1];
	for (int i = 1; i <= chang + 1; i++) {
		m[i]
		    = 'a';
	}
	long long u = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			m[u] = c[i];
			u++;
		}
	}
	long long sum = 0;
	for (int i = 1; i <= chang / 2; i++) {
		if (m[i] != m[chang - i + 1]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n;
long long ans, a[200010], b[200010];
char c[200010], d[200010];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		b[n - i + 1] = a[i];
		d[n - i + 1] = c[i];
	}
	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
		b[i] += b[i - 1];
	}
	int i = 1, j = 1;
	while (i <= n and j <= n) {
		if(c[i] == d[j]) ans += (min(a[i], b[j]) - max(a[i - 1], b[j - 1]));
		if(a[i] < b[j]) i++;
		else if(a[i] > b[j]) j++;
		else i++, j++;
	}
	cout << (a[n] - ans) / 2;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct s {
	int o;
	char z;
}a[200005];
int n;
long long l;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].o >> a[i].z;
		l += a[i].o;
	}
	long long i = 1, sum = 0;
	int j1 = 1, j2 = 1;
	while (i <= l / 2) {
		if (a[j1].z != a[n - j2 + 1].z) {
			sum += min(a[j1].o, a[n - j2 + 1].o);
			i += min(a[j1].o, a[n - j2 + 1].o);
			a[j1].o -= min(a[j1].o, a[n - j2 + 1].o);
			a[n - j2 + 1].o -= min(a[j1].o, a[n - j2 + 1].o);
		}
		else
			i += min(a[j1].o, a[n - j2 + 1].o);
		if (i > j1)
			j1++;
		if (i > j2)
			j2++;
	}
	cout << sum;
}

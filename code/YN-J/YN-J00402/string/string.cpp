#include <bits/stdc++.h>
using namespace std;

struct hui {
	int m;
	char c;
} a[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long sum = 0, num = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].m >> a[i].c;
	}
	int j = n;
	for (int i = 1; ; ) {
		int ans = min(a[i].m, a[j].m);
		if (i >= j )
			break;
		if (a[i].c == a[j].c) {
			a[i].m -= ans;
			a[j].m -= ans;
		} else {
			sum += ans;
			a[i].m -= ans;
			a[j].m -= ans;
		}
		if (a[i].m == 0)
			i++;
		if (a[j].m == 0)
			j--;
	}
	for (int i = 1; ; ) {
		if (i >= j )
			break;
		if (a[i].c == a[j].c) {
			a[i].m -= min(a[i].m, a[j].m);
			a[j].m -= min(a[i].m, a[j].m);
		} else {
			sum += min(a[i].m, a[j].m);
			a[i].m -= min(a[i].m, a[j].m);
			a[j].m -= min(a[i].m, a[j].m);
		}
		if (a[i].m == 0)
			i++;
		if (a[j].m == 0)
			j--;
	}
	cout << sum;
	return 0;
}
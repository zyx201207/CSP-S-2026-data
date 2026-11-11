#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

struct hw {
	long long b;
	char c;
};
hw a[200010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin >> n;
	string s = "";
	long long o = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i].b >> a[i].c;
		o += a[i].b;
	}
	if (o % 2 == 0) {
		cout << o / 2;
		return 0;
	}
	long long sum = 0;
	long long k;
	char j;

	k = abs(a[n].b - a[1].b);
	if (a[n].b > a[1].b) {
		j = a[n].c;
	} else {
		j = a[1].c;
	}
	if (a[n].c != a[1].c) {
		sum += k;
	}
	for (long long i = 2; i <= n / 2; i++) {
		if (a[i].c != j) {
			k = abs(k - a[n - i + 1].b);
			if (a[i].b > k) {
				j = a[n - i + 1].c;
			}
		}
	}
	k = abs(k - a[n / 2 + 1].b);
	if (a[n / 2].c != a[n / 2 + 1].c) {
		sum += k;
	}
	cout << sum;
	return 0;
}
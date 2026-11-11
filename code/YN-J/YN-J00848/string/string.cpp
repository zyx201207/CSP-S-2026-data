#include <bits/stdc++.h>
using namespace std;

struct node {
	int b;
	char c;
};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	node a[200005];
	cin >> n;
	int l = 0, r = n - 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i].b;
		cin >> a[i].c ;
	}
	long long sum = 0;
	while (l < r) {
		if (a[l].c != a[r].c) {
			if (a[r].b < a[l].b) {
				sum += a[r].b;
				a[l].b -= a[r].b;
				r -= 1;
			} else if (a[r].b > a[l].b) {
				sum += a[l].b;
				a[r].b -= a[l].b;
				l += 1;
			} else {
				sum += a[l].b;
				l += 1;
				r -= 1;
			}
		} else {
			if (a[r].b < a[l].b) {
				a[l].b -= a[r].b;
				r -= 1;
			} else if (a[r].b > a[l].b) {
				a[r].b -= a[l].b;
				l += 1;
			} else {
				l += 1;
				r -= 1;
			}
		}
	}
	cout << sum;
	return 0;
}

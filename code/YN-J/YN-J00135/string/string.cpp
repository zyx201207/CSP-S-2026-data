#include <bits/stdc++.h>
using namespace std;

struct node {
	long long x;
	char c;
} a[200001];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, l, r, s = 0;
	cin >> n;
	l = 0;
	r = n - 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].c;
	}
	int j = 0;
	while (l <= r) {
		if (a[l].c == a[r].c) {
			int m = min(a[l].x, a[r].x);
			//	cout << a[l].x << " " << a[r].x << endl;
			a[l].x = a[l].x - m;
			a[r].x = a[r].x - m;
			//	cout << m << " " << a[l].x << " " << a[r].x << endl;
		} else {
			int m = min(a[l].x, a[r].x);
			//cout << a[l].x << " " << a[r].x << endl;
			a[l].x -= m;
			a[r].x -= m;
			//cout << m << " " << a[l].x << " " << a[r].x << endl;
			s += m;
		}
		if (a[l].x <= 0)
			l++;
		if (a[r].x <= 0)
			r--;
		j++;
	}
	cout << s;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long sum = 0;

struct hw {
	long long a;
	char c;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;

	cin >> n;
	hw a[n + 5] = {};
	bool b = false;
	cin >> a[1].a >> a[1].c;
	for (long long i = 2; i <= n ; i++) {
		cin >> a[i].a >> a[i].c;
		if (a[i].c != a[i - 1].c)
			b = true;
	}
	if (b == false) {
		cout << 0;
		return 0;
	}
	int x = 1, y = n;
	while (x < y) {
		if (a[x].c != a[y].c) {
			if (a[x].a < a[y].a) {
				sum += a[x].a;
				a[y].a -= a[x].a;
				x++;
			} else if (a[x].a >= a[y].a) {
				sum += a[y].a;
				a[x].a -= a[y].a;
				y--;
			}
		} else if (a[x].a >= a[y].a) {
			a[x].a -= a[y].a;
			y--;
		} else if (a[x].a < a[y].a) {
			a[y].a -= a[x].a;
			x++;
		}
	}
	cout << sum;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct f {
	long long x;
	string s;
} ;
f z[200005];
long long n, sum, cnt;

int main() {
	freopen("string.in", 'r', stdin);
	freopen("string.out", 'w', stdin);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> z[i].x >> z[i].s;
		sum += z[i].x;
	}

	int i = 1, j = n;

	while (sum > 0) {
		long long q = min(z[i].x, z[j].x);

		if (z[i].s != z[j].s) {
			cnt += q;
		}

		z[i].x -= q;
		z[j].x -= q;

		if (z[i].x == 0) {
			i++;
		}

		if (z[j].x == 0) {
			j--;
		}

		sum -= 2 * q;
	}

	cout << cnt;
	return 0;
}
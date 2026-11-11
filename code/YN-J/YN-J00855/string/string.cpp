#include <bits/stdc++.h>
using namespace std;

struct node {
	long long k;
	char l;
} b[200001];
long long a, cnt = 0;

void p(long long l, long long r) {
	while (l < r) {
		if (b[l].k < b[r].k) {
			if (b[l].l != b[r].l) {
				cnt += b[l].k;

			}
			b[r].k -= b[l].k;
			l++;
		} else if (b[l].k > b[r].k) {
			if (b[l].l != b[r].l) {
				cnt += b[r].k;
			}
			b[l].k -= b[r].k;
			r--;
		} else {
			if (b[l].l != b[r].k) {
				cnt += b[l].k;
			}
			l++;
			r--;
		}
	}
}

int main() {
	freopen("string.in", "w", stdin);
	freopen("string.out", "r", stdout);
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b[i].k >> b[i].l;
	}
	p(0, a - 1);
	cout << cnt;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int n;
long long sum;

struct egg {
	int num;
	char s;
} a[maxn];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num >> a[i].s;
	}
	int i = 1;
	int j = n;
	while (i != j) {
		if (a[i].s != a[j].s) {
			int mmin = min(a[i].num, a[j].num);
			sum += mmin;
			a[i].num -= mmin;
			a[j].num -= mmin;
			if (a[i].num == 0 && a[j].num == 0) {
				i++;
				j--;
			} else if (a[i].num == 0) {
				i++;
			} else if (a[j].num == 0) {
				j--;
			}
		} else {
			if (a[i].num == a[j].num) {
				i++;
				j--;
			} else if (a[i].num > a[j].num) {
				a[i].num -= a[j].num;
				j--;
			} else {
				a[j].num -= a[i].num;
				i++;
			}
		}
	}
	printf("%lld", sum);

	return 0;
}
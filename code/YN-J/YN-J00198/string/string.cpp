#include <iostream>
#include <cstring>
using namespace std;

const int M = 2e5 + 10;
long long n, ans;
struct yyq {
	long long s;
	char c;
} y[M];

int main() {

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %c", &y[i].s, &y[i].c);
	}

	int l = 1, r = n;

	while (l < r) {
		if (y[l].c != y[r].c) {
			ans += min(y[l].s, y[r].s);
		}
		if (y[l].s > y[r].s) {
			y[l].s -= y[r].s;
			r--;
		} else if (y[l].s < y[r].s) {
			y[r].s -= y[l].s;
			l++;
		} else if (y[l].s == y[r].s) {
			r--;
			l++;
		}
	}

	printf("%d", ans);

	return 0;
}
#include <iostream>
using namespace std;
int gzy, T;
int n;
long long d;
long long pos[2000005];
void solveA() {
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", pos + i);
	}
	if (pos[n] - pos[1] <= d) {
		puts("0");
		return;
	}
	int gc = pos[2] - pos[1];
	long long res = 0;
	for (int len = 1; len < n; len++) {
		if (len * gc <= d) continue;
		if (len * gc >= 2 * d) break;
		res += n - len;
	}
	printf("%lld\n", res);
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &gzy, &T);
	if (gzy >= 11 && gzy <= 12) {
		while (T--) solveA();
		return 0;
	}
	else {
		while (T--) {
			scanf("%d%lld", &n, &d);
			for (int i = 1; i <= n; i++) {
				scanf("%lld", pos + i);
			}
			puts("0");
		}
	}
	return 0;
}
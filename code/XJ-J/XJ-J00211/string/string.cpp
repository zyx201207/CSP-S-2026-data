#include <bits/stdc++.h>
using namespace std;

const int N = 200011;
struct Node {
	int v;
	char c;
} a[N];
int n;
long long len;

int main() {	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	len = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %c", &a[i].v, &a[i].c);
		len += a[i].v;
	}
	long long l = 1, r = len, ans = 0;
	for (int i = 1, j = n; i < j && l <= r; ) {
		int x = min(a[i].v, a[j].v);
		int p1 = a[i].v, p2 = a[j].v;
		a[i].v -= x, a[j].v -= x;
		if (a[i].c != a[j].c) ans += x;
		if (p1 <= p2) i++;
		if (p1 >= p2) j--;
		l += x, r -= x;
	}
	printf("%lld\n", ans);
	return 0;
}

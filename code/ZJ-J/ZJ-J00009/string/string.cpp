#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n;
int a[N];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	int l = 0;
	for (int i = 1; i <= n; i++) {
		scanf(" %d %c", a+i, c+i);
		l += a[i];
	}
	int pos1 = 1, pos2 = n, id = 1;
	long long ans = 0;
	while (1) {
//		printf("pos1 : %d, pos2 : %d, id : %d\n", pos1, pos2, id);
		if (a[pos1]-id+1 >= a[pos2]) {
			// [   ]...[ ]
			if (c[pos1] != c[pos2])
				ans += a[pos2];
			id += a[pos2]-1;
		} else {
			// a[pos1]-id+1 < a[pos2]
			if (c[pos1] != c[pos2])
				ans += a[pos1]-id+1;
			a[pos2] -= a[pos1]-id+1;
			pos1++;
			id = 1;
			while (a[pos1] < a[pos2]) {
//				printf(">>> pos1 : %d, pos2 : %d, id : %d\n", pos1, pos2, id);
				if (c[pos1] != c[pos2])
					ans += a[pos1];
				a[pos2] -= a[pos1];
				++pos1;
			}
			// a[pos1] >= a[pos2]
			if (c[pos1] != c[pos2])
				ans += a[pos2];
			id += max(a[pos2]-1, 0);
		}
		id++;
		pos2--;
		if (id > a[pos1]) {
			id = 1;
			pos1++;
		}
		if (pos1 >= pos2)
			break;
	}
	printf("%lld", ans);
}
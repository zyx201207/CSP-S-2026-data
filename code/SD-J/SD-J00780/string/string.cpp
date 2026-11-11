#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
inline ll read() {
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * f;
}

struct node {
	ll a;
	char c;
}zifu[maxn];

ll n, ans = 0, lid = 1, rid, lft = 1, rht;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	n = read();
	rht = n;
	for (int i = 1; i <= n; i ++) {
		zifu[i].a = read();
		zifu[i].c = getchar();
	}
	for (int i = 1; i <= n; i ++) {
		rid = rid + zifu[i].a;
	}
	while (lid <= rid && lft <= n && rht >= 1) {
		if (zifu[lft].c == zifu[rht].c) {
			if (zifu[lft].a > zifu[rht].a) {
				lid += zifu[rht].a;
				rid -= zifu[rht].a;
				zifu[lft].a -= zifu[rht].a;
				rht --;
			}
			else if (zifu[lft].a == zifu[rht].a) {
				lid += zifu[lft].a;
				rid -= zifu[lft].a;
				lft ++;
				rht --;
			}
			else {
				lid += zifu[lft].a;
				rid -= zifu[lft].a;
				zifu[rht].a -= zifu[lft].a;
				lft ++;
			}
		}
		else {
			ans += min(zifu[lft].a, zifu[rht].a);
			if (zifu[lft].a > zifu[rht].a) {
				lid += zifu[rht].a;
				rid -= zifu[rht].a;
				zifu[lft].a -= zifu[rht].a;
				rht --;
			}
			else if (zifu[lft].a == zifu[rht].a) {
				lid += zifu[lft].a;
				rid -= zifu[lft].a;
				lft ++;
				rht --;
			}
			else {
				lid += zifu[lft].a;
				rid -= zifu[lft].a;
				zifu[rht].a -= zifu[lft].a;
				lft ++;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

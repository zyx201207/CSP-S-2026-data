#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005], MAXN = -0x3f;
void cmp(int x, int c, long long cur) {
	if (c == m) {
		MAXN = max(MAXN, cur);
		return ;
	}
	for (int i = x + 1; i <= n; i++) {
		cmp(i, c + 1, cur & a[i]);
		cmp(i, c, cur);
	}
	return ;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cmp(i, 1, a[i]);
	}
	cout << MAXN;
    return 0;
}

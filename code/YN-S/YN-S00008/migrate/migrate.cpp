#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

inline ll read() {
	ll num = 0, sign = 1;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		sign = ch == '-' ? -1 : 1, ch = getchar();
	while ('0' <= ch && ch <= '9')
		num = (num << 1) + (num << 3) + ch - '0', ch = getchar();
	return sign < 0 ? -num : num;
}
const int MAXN = 2e6 + 8;
int c, t;
int n, d;
ll x[MAXN];
ll dsz, disc[MAXN];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	int cnt = 0;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i], disc[++dsz] = x[i];
		cout << cnt, cnt--;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int MAXN = 500086;
long long c, n, m, d, q, x, y;
int w[500086], a[510][500086], b[500086];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n;
	d = c * 114514 + 4;
	d %= 256648;
	q = n * 54188 + 114514;
	q %= 13759;
	q -= 2733;
	cout << d << endl;;
	cout << q;
	return 0;
}

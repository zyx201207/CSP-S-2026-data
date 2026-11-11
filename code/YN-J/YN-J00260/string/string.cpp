#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, ans, t, w, cnt;

struct yyy {
	long long w;
	char c;
} a[N];

string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].w >> a[i].c;
	}
	t = 1, w = n;
	while (t != w) {
		if (a[t].c != a[w].c) {
			ans += min(a[t].w, a[w].w);
		}
//		cout << t << " " << w << " " << a[t].w << " " << a[w].w << " " << ans << " ";
		long long f = min(a[t].w, a[w].w);
		a[t].w -= f;
		a[w].w -= f;
//		cout << a[t].w << " " << a[w].w << endl;
		if (a[t].w == 0) {
			t++;
		}
		if (a[w].w == 0) {
			w--;
		}
//		cout << t << " " << w << " " << a[t].w << " " << a[w].w << " " << ans << endl;
		cnt++;
	}
	cout << ans;
	return 0;
}
/*
7
2 a
2 b
1 c
1 d
1 a
1 c
1 d
*/
//by yyy 2026.10.31
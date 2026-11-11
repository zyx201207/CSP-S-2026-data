#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
struct Str {
	long long num;
	char c;
} a[N];


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long posi = 1, posj = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num >> a[i].c;
		posj += a[i].num;
	}
	int l = 1, r = n;
	while (posi <= posj) {
		long long tmp = min(a[l].num, a[r].num);
		if (a[l].c != a[r].c)
			ans += tmp;
		posi += tmp;
		posj -= tmp;
		a[l].num -= tmp;
		a[r].num -= tmp;
		l += (a[l].num == 0);
		r -= (a[r].num == 0);
	}
	cout << ans << endl;
	return 0;
}

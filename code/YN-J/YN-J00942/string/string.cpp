#include <bits/stdc++.h>
using namespace std;

struct stringg {
	long long a, b, ad, bd;
	char c;
};
stringg a[int(2e5 + 6)];
long long n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long idx = 1, l, ans = 0; //idx=size

	for (long long i = 0; i < n; i++) {
		cin >> l >> a[i].c;
		a[i].a = idx;
		a[i].b = idx + l - 1;
		idx += l;
	}
	for (long long i = 0; i < n; i++) {
		a[i].ad = idx - a[i].a ;
		a[i].bd = idx - a[i].b ;
	}
	for (long long i = 0; a[i].b <= idx / 2 + 1; i++) {
		for (long long j = n - 1; a[j].a >= idx / 2 + 1; j--) {
			//	cout << a[i].a << ' ' << a[i].b << ' ' << a[i].ad << ' ' << a[i].bd << ' ' << a[i].c << '\n';
			//	cout << a[j].a << ' ' << a[j].b << ' ' << a[j].ad << ' ' << a[j].bd << ' ' << a[j].c << '\n';
			if (a[i].ad >= a[j].a && a[i].bd <= a[j].b) {
				if (a[i].c != a[j].c) {
					if (a[i].b <= idx / 2 + 1 ) {
						ans += min(a[i].ad - a[j].a + 1, a[j].b - a[i].bd + 1);
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
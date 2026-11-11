#include <bits/stdc++.h>
using namespace std;

struct aaa {
	long long be;
	long long ed;
	char nm;
};
aaa a[100005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long s = 1;
	int n;
	cin >> n;
	int u = 0;
	while (u < n) {
		a[u].be = s;

		cin >> a[u].ed;
		cin >> a[u].nm;
		s += a[u].ed;
		u++;
	}
	long long yy = s / 2 ;
	long long r = a[n - 1].be;
	long long l = a[0].ed ;
	int ll = 0, rr = n - 1;
	int z = a[0].nm, y = a[n - 1].nm;
	int g = 0;
	for (long long pp = s; pp >= yy; pp--) {
		if (s + 1 - pp > l) {
			ll++;
			l += a[ll].ed;
			z = a[ll].nm;
		}
		if (pp < r) {
			rr--;
			r = a[rr].be;
			y = a[rr].nm;
		}
		if (z != y)
			g++;
	}
	cout << g;


}

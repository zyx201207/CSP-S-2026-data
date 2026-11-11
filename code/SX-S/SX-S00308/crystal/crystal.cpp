#include <bits/stdc++.h>
using namespace std;
int n;
long long m, z;
long long a[500005];
bool dc = true;

bool cmp(long long aa, long long bb) {
	return aa > bb;
}
long long c;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if (i >= 4) {
			if (abs(a[i] - a[i - 1]) != abs(a[i - 1] - a[i - 2])) {
				dc = false;

			}
		}
	}
	long long res;
	if (dc == true) {
		c = abs(a[2] - a[1]);
		res = 1;
		while (z + z + c <= m) {
			z = z + z + c;
			res++;
		}
	}

	if (dc == false) {
		long long cz = 0, o = 0;
		sort(a + 1, a + n + 1, cmp);

//		cout << "ÅÅÐòºó£º";
		for (int h = 1; h <= n; h++) {
//			cout << a[h] << " " << endl;
		}
		for (int i = 1; i <= n; i++) {
			cz = 0, o = 0;
			for (int j = i; j <= n; j++) {
				c = a[i] - a[j];
				cz += c;
				if (cz > m) {
					break;
				}
				o++;

			}
			res = max(res, o);
//			cout << "O:" << o << endl;
		}
	}
	cout << res;
	return 0;
}
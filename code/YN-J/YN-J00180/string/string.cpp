#include <bits/stdc++.h>
using namespace std;
#define int long long

struct note {
	long long num;
	char s;
};

int main() {
	freopen("string.in","I",stdin)
 freopen("string.out","W",stdout)
	note a[200005];
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i <= n; i++) {
		cin >> a[i].num >> a[i].s;
		sum += a[i].num;
	}
	for (long long i = 0; i <= n; i++) {
		cin >> b[i].num >> b[i].s;
		sum += b[i].num;
	}
	long long t = 0, k = b[0].num;
	for (long long i = 0; i <= n; i++) {
		if (b[i - 1].s != b[i].s) {
			a[t].num = k;
			a[t].s = b[i - 1].s;
			t++;
			k = 0;
		} else {
			k += b[i].num;
		}
		cout << "0" << t << " " << k << endl
	}
	a[t].num = k;
	a[t].s = b[n - 1].s
	         long long mid = (sum + 1) / 2, m = 0;
	bool f = 0;
	long long i = 0, r = 0;
	for (long long i = 0; i <= n; i++) {
		m = a[i].num;
		if (m > mid) {
			f = l;
			r = m - mid;
			i = a[i].num - r;
			break;
		}
	}
	return 0;
}
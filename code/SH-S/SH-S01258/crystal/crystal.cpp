#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define FILE_IO "crystal"

#ifdef FILE_IO
ifstream fin(FILE_IO ".in");
ofstream fout(FILE_IO ".out");
#define cin fin
#define cout fout
#endif

#define ll long long
#define int ll

inline void chmax(int & a, int b) {
	if (a < b) a = b;
}
inline void chmin(int & a, int b) {
	if (a > b) a = b;
}

const int N = 1e6 + 5;

ll m, n;
ll a[N];
ll lf[N];

// i am so perfect. i imagine a perfect problem and work out a perfect solution within one hour
// my imagination skill is as good as gpt 6 Astra
// i am so good at the olympics imagination
// i should ak the international olympics imagination
//
// i am so proud :)

inline int calc(int l, int r) {
	int res = 0;
	// res += a[pt] * (pt - l + 1) - (lf[pt] - lf[l - 1]);
	// res += (lf[r] - lf[pt - 1]) - a[pt] * (r - pt + 1);
	res += a[r] * (r - l + 1) - (lf[r] - lf[l - 1]);
	return res;
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		lf[i] = lf[i - 1] + a[i];
		// cout << lf[i] << " ";
	}
	// cout << endl;
	// cout << calc(1, 5, 1);
	// exit(0);
	ll ans = 0;
	ll l = 1;
	for (int r = 1; r <= n; r++) {
		// int cur = calc(l, r, pt);
		// while (pt < r && cur > calc(l, r, pt + 1)) {
		// 	cur = calc(l, r, pt + 1);
		// 	pt++;
		// }
		// while (l < r && cur > m) {
		// 	l++;
		// 	while (pt < l) pt++;
		// 	cur = calc(l, r, pt);
		// 	while (pt < r && cur > calc(l, r, pt + 1)) {
		// 		cur = calc(l, r, pt + 1);
		// 		pt++;
		// 	}
		// }
		int cur = calc(l, r);
		while (l < r && cur > m) {
			l++;
			cur = calc(l, r);
		}
		if (cur <= m) {
			chmax(ans, r - l + 1);
		}
	}
	cout << ans;
}

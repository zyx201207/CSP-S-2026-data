#include <bits/stdc++.h>

using namespace std;

const int N = 2000009;

long long n, d, x[N], l[N], r[N], ans, v[N]
long long a[N],b[N],sa[N],sb[N];

int dfs(int fa, int x) {
	
}

void solve() {
	cin >> n >> d;
	for (int i = 0;i <= n+3; ++ i) x[i] = l[i] = r[i] = a[i] = b[i] = sa[i] = sb[i] = v[i] = 0;
	ans = 0;
	for (int i = 1;i <= n;++ i) cin >> x[i];
	
	for (int i = 1, ll = 1; i <= n; ++ i) {
		while (x[i] - x[ll] > d) ll ++;
		l[i] = ll;
	}
	for (int i = n, rr = n; rr >= 1; -- i) {
		while (x[rr] - x[i] > d) rr --;
		r[i] = rr;
	}
	for (int i = 1; i <= n - 1; ++ i) a[i] = a[l[i]] + l[i+1] - l[i], sa[i] = sa[i - 1] + a[i] + 1;

	for (int i = n; i >= 2; -- i) b[i] = b[r[i]] + r[i] - r[i-1], sb[i] = sb[i + 1] + b[i] + 1;

	for (int  i = 1; i <= n; ++ i) {
		long long sar = sa[min(i - 1, l[i + 2] - 1)];
		long long sal = sa[min(i - 1, l[i + 1] - 1)];
		long long sbr = sb[max(i + 2, r[i] + 1)];
		long long sbl = sb[max(i + 2, r[i - 1] + 1)];
		ans += (sar - sal) * (sbl-sbr);
	}	
//	for (long long i = 2; i <= n-2; ++ i) {
//		long long sar = sa[min(i - 1, l[i + 2] - 1)];
//		long long sal = sa[min(i - 1, l[i + 1] - 1)];
//		long long sbr = sb[max(i + 2, r[i] + 1)];
//		long long sbl = sb[max(i + 2, r[i - 1] + 1)];
//		ans += (sar - sal) * (sbl-sbr);
//		cout << "i = " << i << endl;
//		cout << " l[i + 2] - 1: " << l[i + 2] - 1 << " l[i + 1]-1: " << l[i + 1]-1  << " r[i - 1] + 1: " << r[i - 1] + 1  << " r[i] + 1: " << r[i] + 1 << endl;
//		cout << sar << " " << sal << " : " << sbl << " " << sbr << endl;
//		cout << ans << endl; 
//	}
//	for (int i = 1;i <= n; ++ i) cout << x[i] << " l[i]: " << l[i] << " r[i]: " << r[i] << "   a[i]: " << a[i] << " b[i]: " << b[i] << "   sa[i]: " << sa[i] << " sb[i]: " << sb[i] << endl;
	cout << ans << endl;
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, T; cin >> c >> T;
	while (T --)  solve1();
	return 0;
}


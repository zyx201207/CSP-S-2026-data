// 16:12, 还有2h15min，来吧T4 

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e6 + 10;

int n, d, a[N], R[N], L[N];
int f[N], g[N], sf[N], sg[N], e1[N], e2[N], e3[N], e4[N];

int solve() {
	cin >> n >> d;
	for (int i = 0; i <= n + 1; ++ i ) {
		f[i] = g[i] = sf[i] = sg[i] = e1[i] = e2[i] = e3[i] = e4[i] = 0;
	}
	for (int i = 1; i <= n; ++ i ) cin >> a[i];
	for (int i = 1, j = 1; i <= n; ++ i ) {
		while (j <= n && a[j] - a[i] <= d) j ++ ;
		R[i] = j - 1;
		e3[R[i]] ++ ;
	}
	for (int i = n, j = n; i; -- i ) {
		while (j && a[i] - a[j] <= d) j -- ;
		L[i] = j + 1;
		e4[L[i]] ++ ;
	}
	
	for (int i = 1; i <= n; ++ i ) {
		int x = L[i];
		if (x == i) continue;
		if (R[x] > i) continue;
		int lo = x, hi = i - 1, p = -1;
		while (lo <= hi) {
			int mid = lo + hi >> 1;
			if (R[mid] == i) p = mid, lo = mid + 1;
			else hi = mid - 1;
		}
		assert(~p);
		f[i] = p - x + 1;
		sf[i] = f[i] + sf[x];
	}
	for (int i = n; i; -- i ) {
		int x = R[i];
		if (x == i) continue;
		if (L[x] < i) continue;
		int lo = i + 1, hi = x, p = -1;
		while (lo <= hi) {
			int mid = lo + hi >> 1;
			if (L[mid] == i) p = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		assert(~p);
		g[i] = x - p + 1;
		sg[i] = g[i] + sg[x];
	}
//	for (int i = 1; i <= n; ++ i ) {
//		cout << g[i] << " \n"[i == n]; 
//	}
	
	for (int i = 1; i <= n; ++ i ) {
		if (R[i] == i) continue;
		int lo = i, hi = R[i] - 1, p = -1;
		while (lo <= hi) {
			int mid = lo + hi >> 1;
			if (R[mid] == R[i]) p = mid, lo = mid + 1;
			else hi = mid - 1;
		}
		assert(~p); 
		e1[i] = p - i + 1;
	}
	for (int i = 1; i <= n; ++ i ) {
		if (L[i] == i) continue;
		int lo = L[i] + 1, hi = i, p = -1;
		while (lo <= hi) {
			int mid = lo + hi >> 1;
			if (L[mid] == L[i]) p = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		assert(~p);
		e2[i] = i - p + 1;
	}
	
	int res = 0;
	for (int i = 1; i < n; ++ i ) {
		int x = L[i], y = R[i + 1];
		if (x >= i || y <= i + 1) continue;
		int l = 0, r = 0;
		if (R[x] == i + 1) l = sf[x] + e1[x];
		else l = e3[i + 1] - (R[i] == i + 1); 
		if (L[y] == i) r = sg[y] + e2[y];
		else r = e4[i] - (L[i + 1] == i);
		res += l * r;
//		cout << i << ' ' << l << ' ' << r << '\n';
//		if (R[x] == i + 1 || L[y] == i) {
//			res += (sf[x] + e1[x]) * (sg[y] + e2[y]);
//		}
		
	}
	
	// 边界？
	
	return res;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int _, T;
	cin >> _ >> T;
	while (T -- ) cout << solve() << '\n';
	return 0;
} 

/*

10 3
0 3 6 7 8 9 10 13 16 19

*/

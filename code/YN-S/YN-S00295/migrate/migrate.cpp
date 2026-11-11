#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long LL;
const int N = 2e6 + 100;

namespace problem {

bool BEgin;
int n;
LL d;
LL x[N], nxl[N], nxr[N], ctl[N], ctr[N], c[N];
int lowbit(int x) {
	return x & (-x);
}
void upt(int x, LL a) {
	for (int i = x; i <= n; i += lowbit(x))
		c[i] += a;
}
LL query(int x) {
	LL rs = 0;
	for (int i = x; i; i -= lowbit(i))
		rs += c[i];
	return rs;
}
bool ck(LL a, LL b) {
	return std::abs(x[a] - x[b]) <= d;
}
bool ENd;
void solve() {
	std::cerr << (&BEgin - &ENd) / 1024 / 1024 << "\n";
	int C, T;
	std::cin >> C >> T;
	while (T--) {
		std::cin >> n >> d;
		std::fill(x, x + n + 5, 0);
		std::fill(nxl, nxl + n + 5, 0);
		std::fill(nxr, nxr + n + 5, 0);
		std::fill(ctl, ctl + n + 5, 0);
		std::fill(ctr, ctr + n + 5, 0);
		std::fill(c, c + n + 5, 0);
		for (int i = 1; i <= n; i++) {
			std::cin >> x[i];
		}
		for (int l = 1, r = 1; l <= n; l++) {
			while (r + 1 <= n && x[r + 1] - x[l] <= d) {
				r++;
			}
			nxl[l] = r;
		}
		for (int l = n, r = n; l >= 1; l--) {
			while (r - 1 >= 1 && x[l] - x[r - 1] <= d) {
				r--;
			}
			nxr[l] = r;
		}
		for (int i = 1; i <= n; i++) {
			int u = nxr[i], v = i;
			if (nxl[u] == v) {
				ctr[v] = ctr[u] + 1;
			}
		}
		for (int i = n; i >= 1; i--) {
			int v = nxl[i], u = i;
			if (nxr[v] == u) {
				ctl[u] = ctl[v] + 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			upt(i, ctl[i]);
//			std::cerr << i << " " << nxl[i] << " " << nxr[i] << " " << ctl[i] << " " << ctr[i] << "\n";
		}
		LL ans = 0;
		for (int l = 1; l <= n; l++) {
			int r1 = nxl[l];
			int r2 = nxl[r1];
			if (r1 < l + 2 || r1 == r2) {
				continue;
			}
//			int nl = r1 + 1, nr = r2, a1 = 0, a2 = 0;
//			while (nl <= nr) {
//				int mid = (nl + nr) >> 1;
//				if (ck(r1, mid) && ck(r1 - 1, mid) && !ck(r1 - 2, mid)) {
//					a1 = mid;
//					nr = mid - 1;
//				} else if (ck(r1, mid) && !ck(r1 - 1, mid) && !ck(r1 - 2, mid)) {
//					nr = mid - 1;
//				} else {
//					nl = mid + 1;
//				}
//			}
//			nl = r1 + 1, nr = r2;
//			while (nl <= nr) {
//				int mid = (nl + nr) >> 1;
//				if (ck(r1, mid) && ck(r1 - 1, mid) && !ck(r1 - 2, mid)) {
//					a2 = mid;
//					nl = mid + 1;
//				} else if (ck(r1, mid) && !ck(r1 - 1, mid) && !ck(r1 - 2, mid)) {
//					nr = mid - 1;
//				} else {
//					nl = mid + 1;
//				}
//			}
//			if (a2 == 0)
//				continue;
//			ans += 1ll * (ctr[l] + 1) * (query(a2) - query(a1 - 1) + a2 - a1 + 1);
			for (int r = r1 + 1; r <= r2; r++) {
				if (ck(r1, r) && ck(r1 - 1, r) && !ck(r1 - 2, r)) {
					ans += 1ll * (l == nxr[nxr[r]] ? ctr[l] + 1 : 1) * (r == r2 ? ctl[r] + 1 : 1);
//					std::cerr << l << " " << r << " " << 1ll * (ctr[l] + 1) * (ctl[r] + 1) << "\n";
				}
			}
		}
		std::cout << ans << "\n";
	}
}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	problem::solve();
	return 0;
}
/*
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long LL;
const int N = 2e6 + 100;

namespace problem {

bool BEgin;
int n;
LL d;
LL x[N], nxl[N], nxr[N], ctl[N], ctr[N];
bool ck(LL a, LL b) {
	return std::abs(x[a] - x[b]) <= d;
}
bool ENd;
void solve() {
	std::cerr << (&BEgin - &ENd) / 1024 / 1024 << "\n";
	int C, T;
	std::cin >> C >> T;
	while (T--) {
		std::cin >> n >> d;
		std::fill(x, x + n + 5, 0);
		std::fill(nxl, nxl + n + 5, 0);
		std::fill(nxr, nxr + n + 5, 0);
		std::fill(ctl, ctl + n + 5, 0);
		std::fill(ctr, ctr + n + 5, 0);
		for (int i = 1; i <= n; i++) {
			std::cin >> x[i];
		}
		LL ans = 0;
		for (int o = 1; o <= n; o++) {
			for (int l = o, r = o; l <= n; l++) {
				while (r + 1 <= n && x[r + 1] - x[l] <= d) {
					r++;
				}
				nxl[l] = r;
			}
			for (int l = n, r = n; l >= o; l--) {
				while (r - 1 >= o && x[l] - x[r - 1] <= d) {
					r--;
				}
				nxr[l] = r;
			}
			nxl[n] = n + 1;
			std::vector<int> tp(n + 5);
			for (int i = o + 1; i <= nxl[o]; i++)
				tp[o] = 1;
			for (int i = nxl[nxl[o]], lst = nxl[o] + 1; i <= n; i = nxl[i]) {
				for (int j = lst; j <= i; j++) {
					if (tp[lst - 1] == 2 && ck(lst - 1, j) && !ck(lst - 2, j))
						tp[j] = 2, ans++;
					if (tp[lst - 1] == 2 && ck(lst - 1, j) && ck(lst - 2, j))
						tp[j] = 3;
					if (tp[lst - 1] == 1 && tp[lst - 2] == 1 && ck(lst - 1, j) && ck(lst - 2, j) && !ck(lst - 3, j))
						tp[j] = 2, ans++;
					if (tp[lst - 1] == 1 && tp[lst - 2] == 1 && ck(lst - 1, j) && ck(lst - 2, j) && ck(lst - 3, j))
						tp[j] = 3;
					if (tp[lst - 1] == 1 && tp[lst - 2] == 1 && ck(lst - 1, j) && !ck(lst - 2, j) && !ck(lst - 3, j))
						tp[j] = 1;
				}
				lst = i + 1;
			}
		}
		std::cout << ans << "\n";
	}
}
}

int main() {
	freopen("migrate1.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	problem::solve();
	return 0;
}
*/
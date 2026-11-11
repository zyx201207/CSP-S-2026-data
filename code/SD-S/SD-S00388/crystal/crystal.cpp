#include <bits/stdc++.h>
using namespace std;
/*
#define DBGMODE 0
#define dbg if(DBGMODE)cout
#define dnl if(DBGMODE)cout<<'\n'
#define ifd if(DBGMODE)
*/
const int N = 5e5 + 3;
int n, m;
long long pfx[N], a[N];
bool check (int mid, long long tgt, int piv) {
//	dbg << "mid: " << mid << ", tgt: " << tgt << ", piv: " << piv << '\n';
	long long src = pfx[piv] - pfx[mid - 1];
	long long req = tgt * (piv - mid + 1);
//	dbg << "src: " << src << ", req: " << req << '\n';
	return (req - src) <= m;
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
//  freopen ("C:\\Users\\Administrator\\Desktop\\crystal\\crystal3.in", "r", stdin);
//	freopen ("log.txt", "w", stdout);
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++ i) {
		pfx[i] = pfx[i - 1] + a[i];
	}
	long long maxx = a[n], minn = a[1];
	int ans = 0;
	for (int ptg = 1; ptg <= n; ++ ptg) {
		long long tgt = a[ptg];
//		dbg << "================ tgt: " << tgt << "================\n";
		while (a[ptg + 1] <= tgt && ptg < n) {
			++ ptg;
		}
//		dbg << "ptg: " << ptg << '\n';
		int l = 1, r = ptg;
		while (l < r) {
			int mid = (l + r) >> 1;
//			dbg << "========================\n";
//			dbg << "l: " << l << ", r:" << r << ", mid:" << mid << '\n';
			if (check(mid, tgt, ptg)) {
//				dbg << "accepted\n";
				r = mid;
			} else {
//				dbg << "failed\n";
				l = mid + 1;
			}
		}
//		dnl;
//		dbg << "full from: " << l << '\n';
//		dbg << "current length: " << ptg - l + 1 << '\n';
		ans = max(ans, ptg - l + 1);
	}
	cout << ans;
	return 0;
}
/*
int main_backup () {
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
    freopen ("C:\\Users\\Administrator\\Desktop\\crystal\\crystal3.in", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	sort (a + 1, a + 1 + n);
	long long maxx = a[n], minn = a[1];
	int ans = 0;
	int bestptg;
	for (int ptg = 1; ptg <= n; ++ ptg) {
		dbg << "======== pivot: " << ptg << " ========\n";
		dbg << "a[ptg]: " << a[ptg] << '\n';
		int sumcst = 0, start = ptg + 1;
		while (start > 1 && sumcst < m) {
			-- start;
			sumcst += a[ptg] - a[start];
			dbg << "a[start]: " << a[ptg] << '\n';
			dbg << "start: " << start << ", sumcst: " << sumcst << '\n';
		}
		if (sumcst > m) {
			dbg << "start currected\n";
			++ start;
		}
		dbg << "start res: " << start;
		dnl;
		if (ans < ptg - start + 1) {
			ans = ptg - start + 1;
			bestptg = ptg;
		}
		// ans = max(ans, ptg - start + 1);
	}
	cout << ans << ' ' << bestptg;
	return 0;
}
*/

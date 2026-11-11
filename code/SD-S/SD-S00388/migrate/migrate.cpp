#include <bits/stdc++.h>
using namespace std;
/*
#define DBGMODE true
#define dbg if(DBGMODE)cout
#define dnl if(DBGMODE)cout<<'\n'
#define ifd if(DBGMODE)
*/
#define INF 2147483647
const int N = 203;
int c, t, x[N], n, d;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --) {
		int ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; ++ i) {
			cin >> x[i];
		}
		for (int A = 1; A <= n - 2; ++ A) {
			for (int B = A + 2; B <= n; ++ B) {
				int mdis = INF, mdcnt;
//				dbg << "======== A: " << A << ", B: " << B << " ========\n";
				int cntnodes = B - A - 1;
				int maxmask = (1 << cntnodes);
				for (int mask = 1; mask < maxmask; ++ mask) {
					int rusednds = 0;
//					dbg << "--------\n";
					int split[13] = {0};
					int copy = mask, j = 9;
					while (copy) {
						int curp = 1 << j;
						if (curp <= copy) {
							copy -= curp;
							split[j] = 1;
						}
						-- j;
					}
//					ifd for (int i = 10; i >= 0; -- i) {
//						cout << split[i] << ' ';
//					}
//					dnl;
					int cmdis = -INF;
					vector <int> nsld;
					nsld.push_back(A);
					for (int i = 0; i < cntnodes; ++ i) {
						if (split[i]) {
							int curp = A + 1 + i;
							nsld.push_back(curp);
							++ rusednds;
						}
					}
					nsld.push_back(B);
//					ifd for (auto x : nsld) {
//						cout << x << ' ';
//					}
//					dnl;
					for (int i = 0; i < nsld.size() - 1; ++ i) {
//						dbg << "this dis: " << x[nsld[i + 1]] - x[nsld[i]] << '\n';
						cmdis = max(cmdis, x[nsld[i + 1]] - x[nsld[i]]);
					}
//					dbg << "cmdis: " << cmdis << '\n';
//					dbg << "rusednds: " << rusednds << '\n';
					if (rusednds < mdis) {
//						dbg << "update mdis\n"; 
						mdcnt = 1;
						mdis = rusednds;
					} else if (rusednds == mdis) {
						++ mdcnt;
					}
				}
//				dbg << "--------\n";
//				dbg << "mdcnt: " << mdcnt << '\n';
				if (mdcnt == 2) {
//					dbg << "ans updated\n";
					++ ans;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

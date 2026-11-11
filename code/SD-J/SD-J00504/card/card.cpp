#include <bits/stdc++.h>
using namespace std;
//#define DBGMODE true
//#define dbg if(DBGMODE)cout
//#define ifd if(DBGMODE)
//#define dnl if(DBGMODE)cout<<'\n'
const int N = 500003;
int n, m, a[N], ans[N];
stack <int> stk;
bool bolt[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
//	dbg << "other\n";
	for (int round = 1; round <= n; ++ round) {
		for (int i = 1; i <= n; ++ i) {
			bolt[i] = 0;
		}
		while (stk.size()) {
			stk.pop();
		}
//		dbg << "=============== round: " << round << " ===============\n";
		for (int i = round; i <= n; ++ i) {
//			dbg << "===============\n";
			if (bolt[a[i]]) {
//				dbg << "case 1\n";
				while (stk.top() != a[i]) {
//					dbg << "pop: " << stk.top() << '\n';
					bolt[stk.top()] = 0;
					stk.pop();
				}
			} else {
//				dbg << "case 2\n";
				bolt[a[i]] = 1;
				stk.push(a[i]);
			}
//			ifd {
//				for (int i = 1; i <= m; ++ i) {
//					cout << bolt[i] << ' ';
//				}
//				dnl;
//			}
		}
		for (int i = 1; i <= m; ++ i) {
			if (bolt[i]) {
				++ ans[i];
			}
		}
	}
	for (int i = 1; i <= m; ++ i) {
		cout << ans[i] << ' ';
	}
	return 0;
}

/*
1 3
1 3 2
1
1 3
*/

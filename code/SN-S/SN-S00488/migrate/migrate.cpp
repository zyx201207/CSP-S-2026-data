//杨皓循 SN-S00488 
#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace sol {
	int a[5005];
	int b[5005][305];

	int cnt[5005], tim[5005];
	void main() {
		int n,d;
		cin >> n >> d;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
//			b[i][1] = b[i][2] = b[i][3] = 0;
			memset(b,0,sizeof(b));
		}

		for(int i = 1; i <= n; ++i) {
			for(int j = i+1; j <= n; ++j) {
				if(a[j] - a[i] > d) {
					break;
				}
//				b[i][1] = b[i][2],b[i][2] = b[i][3],b[i][3] = j;
				b[i][j-i] = j;
			}
//			cout << b[i][1] << " " << b[i][2] << " " << b[i][3] << endl;
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = i; j <= n; ++j) {
				cnt[j] = tim[j] = 0;
			}
			cnt[i] = 1;
			queue<int> q;
			q.push(i);
			while(!q.empty()) {
				auto u = q.front();
				q.pop();
//				cerr << u <<" ";
				for(int j = 1; j <= 300; ++j) {
					if(b[u][j] == 0) {
						continue;
					}
					if(tim[b[u][j]] == 0 || tim[b[u][j]] > tim[u]+1) {
						tim[b[u][j]] = tim[u] + 1;
						cnt[b[u][j]] = cnt[u];
					} else if(tim[b[u][j]] == tim[u] + 1) {
//						cnt[b[u][j]] = min(cnt[b[u][j]]+cnt[u],3ll);
						// Known UB: ll overflow
						cnt[b[u][j]] = cnt[b[u][j]]+cnt[u];
					} else {
						continue;
					}
					q.push(b[u][j]);
				}
			}
//			cout << endl;

			for(int j = i; j <= n; ++j) {
				ans += (cnt[j] == 2);
//				cerr << cnt[j] << "@" << tim[j] << " ";
			}
//			cerr << endl;
		}
		cout << ans << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--) {
		sol::main();
	}

}

/*
16:28 feat: initial commit
16:47 feat: a bf?
17:00 fix: xxx

a failed bf.
啥玩意啊 根本调不通，蕉。 
就这样吧。 

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/

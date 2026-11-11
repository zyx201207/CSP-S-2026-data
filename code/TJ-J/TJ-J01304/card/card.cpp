#include<bits/stdc++.h>
using namespace std;
namespace card {
	const int MAXN = 5e5, MAXM = 3e5;
	int n, m;
	int a[MAXN];
	int now[MAXN], cnt, pos[MAXM];
	int ans[MAXM];
	void read() {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
	}
	namespace force {
		bool check() {
			return n <= 500;
		}
		void solve() {
			for (int i = 1; i <= n; i++) {
				memset(now, 0, sizeof now);
				memset(pos, -1, sizeof pos);
				cnt = 0;
				for (int j = i; j <= n; j++) {
					for (int k = 1; k <= cnt; k++) {
						if (now[k] == a[j]) {
							cnt = k - 1;
							break;
						}
					}
					now[++cnt] = a[j];
				}
				for (int k = 1; k <= cnt; k++) {
					ans[now[k]]++;
				}
			}
			for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
		}
	}
	namespace special {
		bool check() {
			for (int i = 2; i <= n; i++)
				if (a[i] < a[i - 1]) return false;
			return true;
		}
		void solve() {
			for (int i = 1; i <= n; i++) {
				if (a[i] != a[i + 1]) printf("%d ", i);
			}
		}
	}
	void solve() {
		if (force::check()) force::solve();
		else if (special::check()) special::solve();
	}
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	card::read();
	card::solve();
	return 0;
}


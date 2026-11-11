#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int dp[N];
int a[N];
int p[N];
int cnt[N];
int vis[N];
int be[N];
mt19937 rng(time(0));
auto st = clock();

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			vis[j] = 1;
			be[j] = 0;
		}
		stack<int >s;
		for (int j = i; j <= n; j++) {
			if (be[a[j]]) {
				while (s.top() != a[j] && !s.empty()) {
					int u = s.top();
					s.pop();
					//	cout << u << " ";
					be[u] = 0;
					vis[u] = 1;
				}
				//	cout << endl;
			} else {
				be[a[j]] = 1;
				vis[a[j]] = 0;
				s.push(a[j]);
			}
		}
		for (int j = 1; j <= m; j++) {
			if (!vis[j])
				cnt[j]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}
/*
4 2
3 15 12 12
*/
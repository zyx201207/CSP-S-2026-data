/*
CSP-J 2026 T4
by hty
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;

int n, m;
int a[N];
int cnt[M];
bool dis[M];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		vector<int>now;
		memset(dis, 0, sizeof dis);
		for (int j = i; j <= n; j++) {
			if (dis[a[j]] == 0) {
				now.push_back(a[j]);
				dis[a[j]] = 1;
			} else {
				int tmp = 0;
				for (int k = 0; k < (int)now.size(); k++) {
					if (now[i] == a[i]) {
						tmp = k;
						break;
					}
				}
				for (int k = tmp; k < (int)now.size(); k++) {
					now.pop_back();
				}
				now.push_back(a[j]);
			}
		}
		for (int tmp : now)
			cnt[tmp]++;
//		now.clear();
	}
	for (int i = 1; i <= m; i++)
		cout << cnt[i] << " ";
	return 0;
}
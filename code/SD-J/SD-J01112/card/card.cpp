#include <bits/stdc++.h>
const int N = 5e5 + 5;
using namespace std;
int n, m, a[N], flag;
int vis[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) {
			flag = 1;
		}
	}
	if (!flag) {
		map<int, int> mp;
		for (int i = 2; i <= n; i++) {
			if (a[i] > a[i - 1]) {
				mp[a[i - 1]] = i - 1;
			}
		}
		for (int i = 1; i <= m; i++) {
			cout << mp[i] << ' ';
		}
		return 0;
	}
	if (m <= 2) {
		int cnt0 = 0, cnt1 = 0;
		if (a[n] == 1) {
			cout << n << ' ';
			for (int i = 1; i <= n; i++) {
				if (a[i] == 2) {
					cnt0++;
				}
			}
			cout << cnt0;
		} else {
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) {
					cnt1++;
				}
			}
			cout << cnt1 << ' ' << n;
		}
		return 0;
	} 
	for (int i = 1; i <= n; i++) {
		map<int, bool> mp;
		deque<int> ck;
		for (int j = i; j <= n; j++) {
			if (mp[a[j]]) {
				while (ck.front() != a[j]) {
					mp[ck.front()] = 0;
					ck.pop_front();
				}
			} else {
				ck.push_front(a[j]);
				mp[a[j]] = 1;
			}
		}
		while (ck.size()) {
			vis[ck.front()]++;
			ck.pop_front();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << vis[i] << ' ';
	}
	return 0;
}

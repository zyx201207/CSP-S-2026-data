#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt[203], a[506];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int zhan[506], top = 0;
		bool o[203] = {false};
		for (int j = i; j <= n; j++) {
			if (o[!a[j]]) {
				top++;
				zhan[top] = a[j];
				o[a[j]] == true;
			} else {
				for (int i = 1; i <= top; i++) {
					if (zhan[i] == a[j]) {
						top = i - 1;
					}
				}
				top++;
				zhan[top] = a[j];
			}
		}
		for (int i = 1; i <= top; i++) {
			cnt[zhan[i]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}
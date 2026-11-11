#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 10;
const ll M = 3e5 + 10;
ll n, m;
ll a[N];
ll pos[N];
ll ans[N];
ll st[N], idx = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);


	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		idx = 1;
		for (int j = 0; j <= n; j++) {
			pos[j] = 0;
		}
		for (int j = 1; j <= n; j++) {
			st[j] = 0;
		}
		for (int j = i; j <= n; j++) {
//			if (pos[a[j]] == 0 || pos[a[j]] >= idx) {
//				st[idx++] = a[j];
//				pos[a[j]] = idx - 1;
//			} else {
//				idx = pos[a[j]] + 1;
//			}
			if (pos[a[j]] >= 1 && pos[a[j]] < idx) {
				idx = min(idx, pos[a[j]] + 1);
			} else {
				st[idx] = a[j];
				pos[a[j]] = idx;
				idx++;
			}
		}
		for (int j = 1; j < idx; j++) {
			ans[st[j]]++;
			//cout << st[j] << " ";
		}
		//cout << endl;
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}


	return 0;
}
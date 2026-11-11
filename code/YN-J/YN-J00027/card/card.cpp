#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1000010;
ll n, m, ans, a[N], cnt[N], gamecnt[N];
bool ins[N], vis[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		vis[a[i]] = true;
	}

	for (int k = 1; k <= n; k++) {
		memset(ins, false, sizeof(ins));
		memset(cnt, 0, sizeof(cnt));
		stack<ll> q;
		for (int i = k; i <= n; i++) {
			if (ins[a[i]]) {
				while (!q.empty() && a[q.top()] != a[i]) {
					ll num = a[q.top()];
					q.pop();
					//cout << "now back is:" << num << endl;
					//cout << "pop:" << num << endl;
					cnt[num]--;
					//cout << num << " cnt:" << cnt[num] << endl;
					if (cnt[num] <= 0) {
						ins[num] = false;
						//cout << num << "out" << endl;
					}
				}
				if (!q.empty() && a[q.top()] == a[i]) {
					ll num = a[q.top()];
					//cout << "now back is:" << num << endl;
					//cout << "pop:" << num << endl;
					cnt[num]--;
					if (cnt[num] <= 0)
						ins[num] = false;
					q.pop();
				}
			}
			q.push(i);
			cnt[a[i]]++;
			//cout << "push:" << a[i] << endl;
			ins[a[i]] = true;
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i])
				continue;
			if (ins[i]) {
				//cout << i << "inside" << endl;
				gamecnt[i]++;
				//cout << i << " gamecnt:" << gamecnt[i] << endl;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			continue;
		cout << gamecnt[i] << ' ';
	}
	return 0;
}

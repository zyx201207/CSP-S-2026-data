#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 514514;
ll n, m, ans[N];
int a[N];
bool v[N];
queue<ll>q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int f = i; f <= n; f++)
			v[f] = 0;
		for (int j = i; j <= n; j++) {
			if (v[a[j]] == 0) {
				v[a[j]] = 1;
				q.push(a[j]);
			} else {
				while (!q.empty()) {
					v[q.front()] = 0;
					q.pop();
				}
				v[a[j]] = 0;
				q.push(a[j]);
			}
		}
		while (!q.empty()) {
			ll k = q.front();
			ans[k]++;
			q.pop();
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}
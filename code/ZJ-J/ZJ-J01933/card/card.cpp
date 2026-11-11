#include <bits/stdc++.h>
using namespace std;
long long n, m;
const long long N = 5e5 + 5;
long long a[N], ans[N];
bitset<N> vis;
stack<long long> ca; 
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (long long i = 1;i <= n; i++) cin >> a[i];
	for (long long i = 1;i <= n; i++) {
		for (int j = i;j <= n; j++) 
			if(!vis[a[j]]) ca.push(a[j]), vis[a[j]] = true;
			else while (ca.top() != a[j]) vis[ca.top()] = false, ca.pop();
		while(!ca.empty()) ca.pop();
		for (long long k = 1;k <= m; k++) {
			if (vis[k]) ans[k]++;
			vis[k] = false;
		}
	}
	for (long long i = 1;i <= m ;i++) cout << ans[i] << ' ';
	return 0;
}
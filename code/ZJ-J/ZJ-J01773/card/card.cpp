#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int n, m, x, a[N], s[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int k = 1; k <= n; k ++) {
		stack<int> sta;
		bool f[m + 1] = {};
		for (int i = k; i <= n; i ++)
			if (f[a[i]] == false) {
				f[a[i]] = true;
				sta.push(a[i]);
			} else while (sta.top() != a[i]) {
					f[sta.top()] = false;
					sta.pop();
				}
		for (int i = 1; i <= m; i ++)
			if (f[i]) s[i] ++;
	}
	for (int i = 1; i <= m; i ++) cout << s[i] << ' ';
}
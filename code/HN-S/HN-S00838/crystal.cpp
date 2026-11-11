#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, res = 0;
int a[500005], b[500005], q[500005];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	if(a[1] < 0) {
		int num = a[1];
		for(int i = 1; i <= n; i ++)
			a[i] = a[i] - num;
	}
	for(int i = 1; i <= n; i ++)
		q[i] = q[i - 1] + a[i];
	int id = 0;
	for(int i = 1; i <= n; i ++) {
		while((i - id + 1) * a[i] - (q[i] - q[id - 1]) > m)
			id ++;
		res = max(res, i - id + 1);
	}
	cout << res;
	return 0;
}

#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
const int N = 200010;

bool b[N];
int n, m, mx, a[N], ans[30], bin[30][N];

void calc(int i) {
	int cur = 0, x = a[i];
	while(x) {
		bin[cur][i] = x & 1;
		x >>= 1;
		cur++;
	}
	mx = max(mx, max(cur - 1, 0ll));
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i], calc(i);
	for(int i = mx; i >= 0; i--) {
		int cnt = 0;
		for(int j = 1; j <= n; j++)
			if(!b[j] and bin[i][j] == 1)
				cnt++;
		if(cnt >= m) {
			ans[i] = 1;
			for(int j = 1; j <= n; j++)
				if(!b[j] and bin[i][j] == 0)
					b[j] = true;
		}
	} 
	int res = 0;
	for(int i = mx; i >= 0; i--)
		res = res * 2 + ans[i];
	cout << res << '\n';
	return 0;
}
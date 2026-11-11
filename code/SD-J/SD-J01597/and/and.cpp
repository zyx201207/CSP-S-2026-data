#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, m, ret;
int a[N];
bool vis[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	for (int i = 29, o = (1 << 29), num = 0; i >= 0; -- i, o >>= 1, num = 0) {
		for (int j = 1; j <= n; ++ j) if (!vis[j] && a[j] & o) ++ num;
		if (num >= m) {
			ret += o;
			for (int j = 1; j <= n; ++ j) if (!(a[j] & o)) vis[j] = true;
		}
	}
	cout << ret << '\n';
	return 0;
}


#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define zxh(x, y, z, qwq) for(int qwq = x; qwq <= y; qwq += z)
#define dxh(x, y, z, qwq) for(int qwq = x; qwq >= y; qwq -= z)
using namespace std;

const int MAXN = 2e6 + 10;
int c, T, x[MAXN];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T--) {
		int n, d, ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		vector<int> g[n + 10];
		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= i + d; j++) {
				if(i != j && j <= n) g[i].pb(x[j]);
			}
		}
		for(int i = 1; i <= n; i++) {
			int sum = 0;
			for(int v : g[i]) {
				sum++;
			}
			if(sum == 2){
				ans++;
			}
		}
		cout << ans - 1 << endl;
	}
	return 0;
}

/*
Trick||Treat!
Oct31==Dec25?
*/

//我左边这个哥们吃播来的 

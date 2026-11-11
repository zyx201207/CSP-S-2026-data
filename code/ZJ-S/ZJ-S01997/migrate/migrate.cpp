#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 100;
int c, t, n, d, a[N], shu, minn;
int x[N], ou[N], tot;
void dfs(int xx, int l, int r, int lst)
{
	if(xx > r - l + 1) {
		ou[++ tot] = x[r + 1];
		for(int i = 2; i <= tot; i ++) if(ou[i] - ou[i - 1] > d) {
			tot --;
			return;
		}
		if(minn > tot) {
			minn = tot;
			shu = 1;
		}
		else if(minn == tot) shu ++;
		tot --;
		return ;
	}
	for(int i = lst + 1; i <= r; i ++) {
		ou[++ tot] = x[i];
		dfs(xx + 1, l, r, i);
 		tot --;
		dfs(xx + 1, l, r, lst);
	}
}
signed main() {
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while(t --) {
		cin >> n >> d;
		int p = 0, daan = 0;
		/*
		10 22
0 7 14 21 28 35 42 49 56 63
5
		*/
//		cout << n << ' ' << d << "\n";
//		if(n <= 10) {
//			for(int i = 1; i <= n; i ++) cout << x[i] << " \n"[i == n];
//		}
		for(int i = 1; i <= n; i ++) {
			cin >> x[i];
			if(i > 3 && x[i - 1] - x[i - 2] != x[i] - x[i - 1]) p = 1;
		}
		
		if(n <= 9) {
			int ans = 0;
			for(int i = 1; i <= n; i ++) {
				for(int j = i + 2; j <= n; j ++) {
					for(int k = 1; k <= tot; k ++) ou[k] = 0;
					tot = 0;
					shu = 0, minn = 1e9;
					ou[++ tot] = x[i];
					dfs(1, i + 1, j - 1, i);
					if(shu == 2) ans ++;
				}
			}
			
			cout << ans << "\n";
			continue;
		}
		
		if(!p) {
			int jiz = x[2] - x[1];
//			cout << jiz << ' ' << d << "\n";
			if(d <= jiz) cout << "0\n";
			else {
				int ans = 0;
				int k = d / jiz;
				for(int i = 1; i <= n; i ++) {
					if(i + k + k - 1 <= n) ans ++;
//					ans += (n - i - 1) / k;
//					cout << ans << " \n"[i == n];
				}
				cout << ans << "\n";
			}
		}
		else {
			cout << "0\n";
		}
	}
	return 0;
} 

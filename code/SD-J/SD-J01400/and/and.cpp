#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2E5 + 10;
int a[N]; 
bool vis[N];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false); 
	int n, m, maxn = -INF, ans = INT_MAX;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	int len = (int)log2(maxn + 1);
	for(int i = len; i >= 0; i--) {
		int res = 0;
		for(int j = 1; j <= n; j++) {
			if(a[j] & (1 << i) && !vis[j]) res++;
		}
		if(res < m) continue;
		if(res > m) {
			for(int j = 1; j <= n; j++) {
				if((a[j] & (1 << i)) == 0 && !vis[j]) {
					vis[j] = true;
				}
			}
		}
		if(res == m) {
			for(int j = 1; j <= n; j++) {
				if(vis[j]) continue;
				if(a[j] & (1 << i)) {
					ans &= a[j];
				}
			}
			cout << ans << "\n";
			return 0;
		}
	}
	int cl = 0;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			ans &= a[i];
			if(++cl == m) break;
		}
	}
	cout << ans << "\n";
	return 0;
}
/*
¹öÄ¾ + ¹öÄ¾
¹ö + Ä¾ + ¹ö + Ä¾ 
¹ö + Ä¾¹÷ + Ä¾
Ä¾¹÷ + ¹öÄ¾ 
*/

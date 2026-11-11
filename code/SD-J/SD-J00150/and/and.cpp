#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N];
bool num[N][50], vis[N];
void change(int x, int pos) {
	vector<bool> g;
	while(x != 0) {
		g.push_back(x % 2);
		x /= 2;
	}
	int idx = 0;
	for(int i = g.size() - 1; i >= 0; i--) num[pos][++idx] = g[i];
}
void sol() {
	if(m == 1) {
		int res = 0;
		for(int i = 1; i <= n; i++) res = max(res, a[i]);
		cout << res;
		return ;
	}
	int pos1 = 0, pos2 = 0, maxn = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if((a[i] & a[j]) > maxn) {
				maxn = (a[i] & a[j]);
				pos1 = i, pos2 = j;
			}
		}
	}
	vis[pos1] = vis[pos2] = 1;
	int ans = maxn, cnt = 2;
	while(cnt < m) {
		int maxx = 0, pos = 0;
		for(int i = 1; i <= n; i++) {
			if(vis[i]) continue;
			if((a[i] & ans) > maxx) {
				maxx = (a[i] & ans);
				pos = i;
 			}
		}
		ans = maxx;
		vis[pos] = 1;
		cnt++;
	}
	cout << ans << "\n";
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) change(a[i], i);
	sol();
	return 0;
}
/*
0001 1111
	 0011
	 0001
	 1111
	 0111
*/

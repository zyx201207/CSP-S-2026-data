#include <bits/stdc++.h>
using namespace std;
#define int long long
int C, t, n, d, a[2000005], c[2000005], dp[2000005][7], cnt[2000005][7], fa[2000005], k[10][5], ans;
vector<int>g[2000005];
/*int calc(int l, int r){
	int ret = 0;
	for (int i = l; i <= r; i++){
		int tp = 1, j = i;
		while (j != r){
			int nxt = upper_bound(a + 1, a + n + 1, a[j] + d) - a - 1;
			int x = 0, y = 0;
			for (int i = 0; i <= 2; i++){
				if (a[nxt] - a[j - i] <= d){
					y += k[tp][i];
				}
			}
			if (nxt == j + 1){
				if (y == 2){
					ret++;
				}
				if (y > 2){
					break;
				}
				else if (y == 2){
					tp = 5;
				}
				else{
					tp = 1;
				}
				j = nxt;
				continue;
			}
			for (int i = 0; i <= 2; i++){
				if (a[nxt - 1] - a[j - i] <= d){
					x += k[tp][i];
				}
			}
			if (tp == 2){
				//cout << "&" << upper_bound(a + 1, a + n + 1, a[j - 1] + d) - a - 1 << " " << j << endl;
				ret += upper_bound(a + 1, a + n + 1, a[j - 1] + d) - a - 1 - j;
			}
			else if (tp == 3){
				int rr = upper_bound(a + 1, a + n + 1, a[j - 1] + d) - a - 1;
				int ll = upper_bound(a + 1, a + n + 1, a[j - 2] + d) - a - 1;
				int r = max(j, rr);
				int l = max(j, ll);
				ret += r - l;
			}
			else if (tp == 5){
				ret += nxt - j;
			}
			else if (tp == 6){
				ret += nxt - (upper_bound(a + 1, a + n + 1, a[j - 1] + d) - a) + 1;
			}
			if (y == 1){
				if (x == 1){
					if (nxt == j + 2){
						tp = 2;
					}
					else{
						tp = 3;
					}
				}
				else{
					tp = 4;
				}
			}
			else if (y == 2){
				tp = 6;
			}
			else{
				break;
			}
			j = nxt;
		}
	}
	return ret;
}*/
void dfs(int now){
	for (int u = 0; u < g[now].size(); u++){
		int j = g[now][u];
		dfs(j);
		int x, y, v;
		for (int tp = 1; tp <= 6; tp++){
			x = y = 0;
			int ret = 0, c = cnt[j][tp];
			for (int i = 0; i <= 2; i++){
				if (a[now] - a[j - i] <= d){
					y += k[tp][i];
				}
			}
			if (now == j + 1){/*
				if (now == 4 && j == 3 && tp == 2){
					cout << ret << " " << c << " " << y << endl;
				}*/
				if (y == 2){
					ret += c;
				}
				if (y > 2){
					v = -1;
				}
				else if (y == 2){
					v = 5;
				}
				else{
					v = 1;
				}
				if (v != -1){
					dp[now][v] += ret;
					cnt[now][v] += c;
				}
				continue;
			}
			for (int i = 0; i <= 2; i++){
				if (a[now - 1] - a[j - i] <= d){
					x += k[tp][i];
				}
			}
			if (tp == 2){
				//cout << "&" << upper_bound(a + 1, a + n + 1, a[j - 1] + d) - a - 1 << " " << j << endl;
				ret += (upper_bound(a + 1, a + n + 1, a[j - 1] + d) - a - 1 - j) * c;
			}
			else if (tp == 3){
				int rr = upper_bound(a + 1, a + n + 1, a[j - 1] + d) - a - 1;
				int ll = upper_bound(a + 1, a + n + 1, a[j - 2] + d) - a - 1;
				int r = max(j, rr);
				int l = max(j, ll);
				ret += (r - l) * c;
			}
			else if (tp == 5){
				ret += (now - j) * c;
			}
			else if (tp == 6){
				ret += (now - (upper_bound(a + 1, a + n + 1, a[j - 1] + d) - a) + 1) * c;
			}
			if (y == 1){
				if (x == 1){
					if (now == j + 2){
						v = 2;
					}
					else{
						v = 3;
					}
				}
				else{
					v = 4;
				}
			}
			else if (y == 2){
				v = 6;
			}
			else{
				v = -1;
			}
			if (v != -1){
				dp[now][v] += ret;
				cnt[now][v] += c;
			}
		}
	}
	for (int j = 1; j <= 6; j++){
		ans += dp[now][j];
	}
	cnt[now][1]++;
}
signed main(){
	//freopen("data.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	k[1][0] = 1;
	k[2][0] = k[2][1] = 1;
	k[3][0] = k[3][1] = k[3][2] = 1;
	k[4][0] = 1; k[4][1] = 2;
	k[5][0] = 2;
	k[6][0] = 2; k[6][1] = 2;
	cin >> C >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			for (int j = 1; j <= 6; j++){
				dp[i][j] = cnt[i][j] = 0;
			}
			g[i].clear();
		}
		for (int i = 1; i <= n; i++){
			int nxt = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
			if (nxt == i){
				fa[i] = 0;
			}
			else{
				fa[i] = nxt;
				g[nxt].push_back(i);
			}
		}
		ans = 0;
		for (int i = 1; i <= n; i++){
			if (fa[i] == 0){
				dfs(i);
			}
		}
		//cout << cnt[3][2] << endl;
		cout << ans << '\n';
	}
	return 0;
}

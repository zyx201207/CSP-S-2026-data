#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = LLONG_MIN;
int c, t;

const int N = 2e6 + 10;

int n, d;
int x[N];
int s[N];

int dis[1010][1010];
int f[1010][1010];

void solve(){
	cin >> n >> d;
	memset(s, 0, sizeof s);
	for(int i = 1; i <= n; i ++){
		cin >> x[i];
		for(int j = 1; j <= n; j ++){
			dis[i][j] = inf;
		}
	}
	for(int i = 1; i <= n; i ++){
		int l = i, r = i;
		dis[i][i] = 0;
		int cnt = 1;
		while(r < n){
			bool flag = false;
			while(r + 1 <= n && x[r + 1] - x[l] <= d){
				r ++;
				dis[i][r] = cnt;
				flag = true;
			}
			if(!flag) break;
			cnt ++;
			l = r;
		}
	}
	for(int i =1; i <= n; i ++){
		f[i][i] = 1;
	}
	int ans = 0;
	for(int len = 2; len <= n; len ++){
		for(int l = 1; l <= n; l ++){
			int r = l + len - 1;
			for(int k = l + 1; k < r; k ++){
				if(dis[l][k] != inf && dis[k][r] != inf)
				f[l][r] += f[l][k] * f[k][r];
			}
		}
	}
	int res = 0;
	for(int i =1; i <= n; i ++){
		for(int j = i + 1; j <= n; j ++){
			if(f[i][j] == 2)  res ++;
		}
	}
	cout << res << '\n';
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> t;
	while(t --){
		solve();
	}
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4

2
*/


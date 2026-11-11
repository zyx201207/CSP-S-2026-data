#include <bits/stdc++.h>

using namespace std;
#define int long long

int c,t,a[5005],n,d,ans,k,minn = INT_MAX;
bool fla = true;

void dfs(int x,int y,int b) {
	if(b > minn || x > y) return;
	if(x == y) {
		if(b == minn) k ++;
		else if(b < minn) {
			k = 1;
			minn = b;
			//cout << b << " ";
		}
		return;
	}
	//dfs(x + 1,y,b + 1);
	for(int j = x + 1;j <= y; ++ j) {
		if(a[j] - a[x] <= d) {
			dfs(j,y,b + 1);
			//if(!fla) cout << x << " " << j << " " << a[j] - a[x] << " " << d << "\n";
		}
		else break;
	}
}

void solve() {
	//int n,d;
	ans = 0;
	cin >> n >> d;
	for(int i = 1;i <= n; ++ i) cin >> a[i];
	for(int i = 1;i <= n; ++ i) {
		for(int j = i + 1;j <= n; ++ j) {
			//if(i == 1 && j == 4) fla = false;
			k = 0;
			minn = INT_MAX;
			dfs(i,j,0);
			if(k == 2) ans ++;
			//cout << k << "\n";
			//cout << i << " " << j << "\n";
			fla = true;
		}
	}
	cout << ans << "\n";
}

signed main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while(t--) {
		solve();
	}

	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

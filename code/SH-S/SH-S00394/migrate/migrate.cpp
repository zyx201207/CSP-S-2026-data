#include <bits/stdc++.h>
using namespace std;

long long a[2000005], c, n, d, minn = 1e9;

void dfs(int u, int v, int len){
	if (u == v){
		if (len < minn){
			minn = len;
			c = 1;
		}
		else if (len == minn) c++;
		return ;
	}
	for (int i = u + 1; i <= v; ++i){
		if (a[i] - a[u] <= d && len + 1 <= minn){
			dfs(i, v, len + 1);
		}
		else return ;
	}
	return ;
}

bool check(int u, int v){
	c = 0;
	minn = 1e9;
	dfs(u, v, 0);
	return (c == 2);
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		long long cnt = 0;
		for (int i = 1; i <= n; ++i){
			for (int j = i + 1; j <= n; ++j){
				if (check(i, j)){
					++cnt;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0; 
}

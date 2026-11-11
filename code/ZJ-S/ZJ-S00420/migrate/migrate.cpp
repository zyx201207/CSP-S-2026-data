#include<bits/stdc++.h>
#define int long long
#define firefly ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);

using namespace std;

const int N = 2e6;
int c, t, n, d, cnt[N], a[N], ans;

void dfs(int st, int ed, int c){
	int sum = 0;
	if(st == ed){
		cnt[c] ++;
		return;
	}
	for(int i = st + 1;i <= ed;i ++){
		sum += a[i] - a[i - 1];
		if(sum <= d) dfs(i, ed, c + 1);
		else break;
	}
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	firefly
	cin >> c >> t;
	while(t --){
		cin >> n >> d;
		ans = 0;
		for(int i = 1;i <= n;i ++)
			cin >> a[i];
		for(int i = 1;i <= n;i ++){
			for(int j = i + 1;j <= n;j ++){
				for(int k = 1;k <= n;k ++) cnt[k] = 0;
				dfs(i, j, 0);
				for(int k = 1;k <= n;k ++)
					if(cnt[k] == 2){
						ans ++;
					}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}


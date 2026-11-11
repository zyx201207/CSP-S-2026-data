#include<bits/stdc++.h>
#define int long long
#define QwQ 0
#define debug cout << "!!!" << '\n';
using namespace std;
int c, T;
int n, d, res = 0x3f3f3f3f3f, sum;
int x[2000010];
void dfs(int i, int j, int cnt){
	if(cnt > res)	return;
	if(i == j){
		res = min(res, cnt);
		return;
	}
	for(int k = i + 1; k <= j; k++){
		if(x[k] - x[i] <= d){
			dfs(k, j, cnt + 1);
		}else	break;
	}
}
void dfs1(int i, int j, int cnt){
	if(cnt == res && i == j){
		sum++;
		return;
	}
	if(cnt >= res)	return;
	for(int k = i + 1; k <= j; k++){
		if(x[k] - x[i] <= d){
			dfs1(k, j, cnt + 1);
		}else	break;
	}
}
signed main(){
	// freopen("migrate.in", "r", stdin);
	// freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		int ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		if(c >= 11 && c <= 12){
			int ca = x[2] - x[1];
			if(d <= ca){
				cout << 0 << '\n';
				continue;
			}
			d = d / ca;
			d = d + (d - 1);
			int l = 1, r = 1 + d;
			cout << max(0ll, n - r + 1) << '\n';
			continue;
		}
		if(c <= 2){
			for(int i = 1; i <= n; i++){
				for(int j = i + 1; j <= n; j++){
					res = 0x3f3f3f3f3f;
					dfs(i, j, 0);
					sum = 0;
					dfs1(i, j, 0);
					if(sum == 2){
						cout << i << ' ' << j << '\n';
						ans++;
					}
				}
			}
			cout << ans << '\n';
			continue;
		}
		cout << 0 << '\n';
	}
	return QwQ;
}
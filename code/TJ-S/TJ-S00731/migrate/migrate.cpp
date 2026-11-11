#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2 * 1e6 + 5;
int c, q, ans, d, n;
int x[N], lst[N], cnt[1005][1005], t[1005][1005];
void dfs(int k, int e, int tm, int b){
	//cout << 1;
	if(k == e){
		if(tm < t[b][e]){
			t[b][e] = tm;
			cnt[b][e] = 1;
		//	cout << 1;
		}
		if(tm == t[b][e])cnt[b][e]++;
		//cout << tm << endl;
		return ;
	}
	int u = x[k] + d;
	for(int i = k + 1; i <= e; i++){
		cout << tm << " " << i << endl;
		if(x[i] < u)dfs(i, e, tm++, b);
	}
//	cout << 1;
}
signed main(){
	cin >> c >> q;
	while(q--){
		cin >> n >> d;
		int maxx = 0, ans = 0;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
			maxx = max(maxx, x[i]);
			lst[x[i]] = i;
		}
		int u = 0;
		
		for(int i = 1; i <= maxx; i++){
			if(lst[i]){
				u = i;
				continue;
			}
			lst[i] = u;
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				cnt[i][j] = 0;
				t[i][j] = LONG_MAX;
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				dfs(i, j, 1, i);
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(cnt[i][j] == 2){
					ans++;
				}
			//	cout << "i: " << i << " j: " << j << " cnt: " << cnt[i][j] << endl;
			}
		}
		cout << ans << " ";
	}
	return 0;
}
/*0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

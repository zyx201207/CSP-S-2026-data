#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int C, T, n, d;
int ans, cnt, minn; 
int a[N];
void dfs(int x, int s, int e){
	if(s > minn) return;
	if(x == e){
		if(s < minn){
			minn = s;
			cnt = 0;
		}
		cnt++;
		return; 
	}
	for(int i = x + 1; i <= e; i++){
		if(a[i] - a[x] > d) break;
		dfs(i, s + 1, e);
	}
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> C >> T;
	while(T--){
		ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				cnt = 0;
				minn = 1e18;
				dfs(i, 0, j);
				if(cnt == 2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}


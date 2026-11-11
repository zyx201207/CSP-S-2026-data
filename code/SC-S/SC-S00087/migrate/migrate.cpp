#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 6;
int x[N];
int n, d;
int vis[N];
int cnt;
bool pd;
void dfs(int a, int dis, int t){
	if(a > t) return;
	if(pd) return;
	if(vis[a] < dis) return;
	//cout << a << endl;
	vis[a] = dis;
	if(a == t){
		cnt++;
		if(cnt == 3) pd = 1;
		return;
	}
	int i = a + 1;
	while(x[i] <= x[a] + d && i <= t) i++;
	i--;
	for(; i > a; i--) dfs(i, dis + 1, t);
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t; cin >> c >> t;
	while(t--){
		cin >> n >> d;
		int ans = 0;
		for(int i = 1; i <= n; i++) cin >> x[i];
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				memset(vis, 0x3f3f, sizeof vis);
				pd = 0;cnt = 0;
				dfs(i, 0, j);
				if(cnt == 2){
					ans++; //cout << i << " " << j << endl;
				} 
				//cout << endl;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

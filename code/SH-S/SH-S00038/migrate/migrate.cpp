#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e3 + 10;
int c,t,a[N],n,d,vis[N],tmp,ans;
void dfs(int k,int s,int cnt){
	if (k == s){
		tmp = min(tmp,cnt);
		return;
	}
	if (k > s)return ;
	for (int i = 1; i <= d;i++){
		if (vis[k + i])dfs(k + i,s,cnt + 1);
	}
}
void dfs2(int k,int s,int cnt){
	if (k == s){
		if (cnt == tmp) ans++;
		return;
	}
	if (k > s)return ;
	for (int i = 1; i <= d;i++){
		if (vis[k + i])dfs2(k + i,s,cnt + 1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		int sum = 0;
		for (int i = 1; i <= n;i++) {
			cin >> a[i];
			vis[a[i]] = 1;
		}
		for (int i = 1; i < n;i++){
			for (int j = i + 1; j <= n;j++){
				tmp = LLONG_MAX;
				dfs(i,j,0);
				ans = 0;
				dfs2(i,j,0);
				if (ans == 2) {
					sum++;
				}
			}
		} 
		cout << sum << "\n";
	}
	return 0;
} 


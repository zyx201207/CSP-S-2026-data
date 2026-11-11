#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int c, t, n, mn = 1e9;
long long d, cnt, x[N], ans;
void dfs1(int u,int v,int num){
	if (u == v){
		mn = min(mn,num);
		return ;
	}
	for (int i = u+1;i <= n;i++){
		if (x[i]-x[u] > d) break;
		dfs1(i,v,num+1);
	}
}
void dfs2(int u,int v,int num){
	if (u == v){
		if (num == mn) cnt++;
		return ;
	}
	for (int i = u+1;i <= v;i++){
		if (x[i]-x[u] > d) break;
		dfs2(i,v,num+1);
	}
}
bool check(int u,int v){
	dfs1(u,v,0);
	dfs2(u,v,0);
	if (cnt == 2) return 1;
	else return 0;
}
void solve(){
	ans = 0;
	cin >> n >> d;
	for (int i = 1;i <= n;i++) cin >> x[i];
	for (int i = 1;i <= n;i++)
		for (int j = i+2;j <= n;j++){
			cnt = 0, mn = 1e9;
			if (check(i,j))
				ans++;
		}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
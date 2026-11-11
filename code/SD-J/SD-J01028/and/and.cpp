#include <bits/stdc++.h>
using namespace std;
using lnt = long long;
/*====================*/
const int N=2e5+10;
lnt a[N],n,m;
lnt ans=0;
/*====================*/
void dfs(int idx,int now,lnt res){
//	cout << res << "\n";
	if (now>m) return ;
	if (now+n-idx+1<m) return;
	if (idx>n){
		if (now==m){
			ans=max(ans,res);
		}
		return;
	}
	if (now==m){
		ans=max(ans,res);
		return;
	}
	dfs(idx+1,now,res);
	dfs(idx+1,now+1,res & a[idx]);
}
/*====================*/
void solve(void){
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	dfs(1,0,4294967295);
	cout << ans;
}
/*====================*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--) solve();
	return 0;
}

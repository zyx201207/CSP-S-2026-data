#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long,long long>
using namespace std; 
const ll N = 2e5+5;
ll a[N],ans,n,M,vis[N];
void dfs(ll k,ll m,ll cnt){
	vis[k] = 1;
	if(m == 0){
		ans = max(ans,cnt);
		return;
	}
	if(k == n+1) return;
	for(ll i = 1;i<=n;i++){
		if(vis[i]) continue;
		
		if(cnt == -1){
			dfs(i,m-1,a[i]);
		}else{
			dfs(i,m-1,a[i]&cnt);	
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll m; 
	cin >> n >> m;
	for(ll i = 1;i<=n;i++){
		cin >> a[i];
	}
	dfs(1ll,m,-1ll);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


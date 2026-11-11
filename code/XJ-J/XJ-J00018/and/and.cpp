#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[200005],maxn = -1e9,f[200005];
bool vis[200005];
int n,m;
void dfs(int step){
	if(step > m){
		ll ans = f[1];
		for(int i = 2;i <= m;i++){
			ans &= f[i];
		}
		maxn = max(ans,maxn);
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		f[step] = a[i];
		vis[i] = 1;
		dfs(step + 1);
		vis[i] = 0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	dfs(1);
	cout << maxn;
	return 0;
}
 

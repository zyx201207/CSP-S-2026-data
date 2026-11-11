#include <bits/stdc++.h>
using namespace std;
int a[2000005],vis[2000005];int c,t,n,d,ans=0;
void dfs(int base,int step){
	if(a[base]+d<a[base+1])return;
	for(int i = 1;i<=d;i++){
		if(a[base+1]==a[base]+i){
			dfs(base+i,step+1);
			vis[base]++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> t;
	cin >> n >> d;
	while(t--){
		for(int i = 1;i<=n;i++){
			cin >> a[i];
		}
		for(int i = 1;i<=n;i++){
			dfs(i,0);
		}
		for(int i = 1;i<=n;i++){
			if(vis[i]==2)ans++;
		}
		cout << ans<<'\n';
	}
	
	return 0;
} 

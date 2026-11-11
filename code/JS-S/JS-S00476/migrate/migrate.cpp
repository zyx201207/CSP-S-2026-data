#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005],vis[2000005],dis[2000005],num[2000005];
void dij(int s){
	for(int i = 0;i<=n;i++){
		vis[i] = 0;
		dis[i] = 2e6;
		num[i] = 0;
	}
	vis[s] = 0;
	dis[s] = 0;
	num[s] = 1;
	for(int i = 1;i<=n;i++){
		int u = 0;
		for(int j = 1;j<=n;j++){
			if(!vis[j] && dis[j] < dis[u]){
				u = j;
			}
		}
		vis[u] = 1;
		int pos1 = lower_bound(x+1,x+n+1,x[u]-d) - x;
		int pos2 = upper_bound(x+1,x+n+1,x[u]+d) - x - 1;
		for(int j = pos1;j<=pos2;j++){
			if(dis[j] == dis[u] + 1){
				num[j] += num[u];
			}
			if(dis[j] > dis[u] + 1){
				dis[j] = dis[u] + 1;
				num[j] = num[u];
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans = 0;
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>x[i];
		}
		for(int i = 1;i<=n;i++){
			dij(i);
			for(int j = 1;j<=n;j++){
				if(num[j] == 2){
					ans++;
				}
			}
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
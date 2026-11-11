#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5000+10;
int n,d,a[N],dis[N][N],ans;
void dfs(int id,int s){
	dis[id][s]++;
	for(int i=id+1;i<=n;i++){
		if(a[i]-a[id]<=d)dfs(i,s+1);
	}
	return;
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(dis,0,sizeof(dis));
		dfs(i,0);
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				if(dis[j][k]==1)break;
				if(dis[j][k]==2){
					ans++;
				}
			}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,te=1;
	cin>>c>>te;
	while(te--){
		solve();
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long c,t,dis[5005][5005],sz[5005][5005],n,m,a[260005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) sz[i][j]=1,dis[i][j]=LLONG_MAX/2;
		for(int i=1;i<=n;i++) dis[i][i]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) for(int j=1;j<i;j++) if(a[i]-a[j]<=m) dis[i][j]=dis[j][i]=1;
		for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(k!=i&&k!=j){
			long long foosball=dis[i][k]+dis[k][j];
			if(foosball==dis[i][j]) sz[i][j]+=sz[i][k]*sz[k][j]; else if(foosball<dis[i][j]) dis[i][j]=foosball,sz[i][j]=sz[i][k]*sz[k][j];
			if(sz[i][j]>5) break;
		}
		for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) if(sz[i][j]==2) ans++;
		cout<<ans<<endl;
	}
	return 0;
}

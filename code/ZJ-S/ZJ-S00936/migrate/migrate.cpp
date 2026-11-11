#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000010];
int dis[5010][5010];
int sum[5010][5010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while (t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=4000010;
				sum[i][j]=0;
			}
		}
		for (int i=1;i<n;i++){
			for (int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					dis[i][j]=dis[j][i]=1;
					sum[i][j]=sum[j][i]=1;
				}
			}
		}
		for (int k=1;k<=n;k++){
			for (int i=1;i<=n;i++){
				if(dis[i][k]==4000010)continue;
				for (int j=1;j<=n;j++){
					if(dis[k][j]==4000010||i==j)continue;
					if(dis[i][j]>dis[i][k]+dis[k][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						sum[i][j]=sum[i][k]*sum[k][j];
					}
					else if(dis[i][j]==dis[i][k]+dis[k][j])sum[i][j]+=sum[i][k]*sum[k][j];
				}
			}
		}
		for (int i=1;i<n;i++)for(int j=i+1;j<=n;j++)if(sum[i][j]==2)ans++;
		cout<<ans<<"\n";
	}
	return 0;
}

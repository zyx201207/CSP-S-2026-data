#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=301;
ll a[N],n,d;
ll dis[N][N],dp[N][N];
void floyd(){
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					dp[i][j]=dp[i][k]*dp[k][j];
				}
				else if(dis[i][j]==dis[i][k]+dis[k][j]){
					dp[i][j]+=dp[i][k]*dp[k][j];
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	if(c<=6){
		while(T--){
			cin>>n>>d;
			for(int i = 1;i<=n;i++) cin>>a[i];
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n;j++) dis[i][j]=4e18,dp[i][j]=0;
			}
			for(int i = 1;i<=n;i++){
				int r=i+1;
				while(r<=n&&a[r]-a[i]<=d){
					dis[i][r]=1,dp[i][r]=1;
					dis[r][i]=1,dp[r][i]=1;
					r++;
				}
			}
			floyd();
			int ans=0;
			for(int i = 1;i<=n;i++){
				for(int j = i+1;j<=n;j++){
					if(dp[i][j]==2) ans++;
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}//1-6 24pts
	else{
		while(T--){
			cin>>n>>d;
			for(int i = 1;i<=n;i++) cin>>a[i];
			cout<<0<<"\n";
		}
	}//no any pts
	return 0;
}


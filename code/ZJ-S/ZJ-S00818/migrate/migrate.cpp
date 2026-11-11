#include<bits/stdc++.h>
using namespace std;
const int N=1e5,M=4e3;
int t,n,m,dp[M][N];
long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int u=0;u<=n;u++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)dp[i-1][j]=0;
			}
			dp[0][u+1]=1;
			int r=u+1,ans=0;
			for(int i=0;i<n;i++){
				int rt=r;
				for(int j=i+u+1;j<=rt;j++){
					for(int e=j+1;e<=n;e++){
						if(a[e]-a[j]>m){
							break;
						}
						dp[i+1][e]+=dp[i][j];
						r=max(r,e);
					}
				}
				for(int j=i+1;j<=r;j++){
					if(dp[i+1][j]==2&&dp[i][j]==0){
						ans++;
					}
				}
				if(r==n){
					break;
				}
			}
			sum+=ans;
		}
		cout<<sum<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5005;
int c,t;
int n,d,a[MAXN],dis[MAXN][MAXN],dp[MAXN][MAXN],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=dp[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			int cnt=1,sum=0;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[j-1]>d)break;
				sum+=a[j]-a[j-1];
				if(sum>d){
					sum=a[j]-a[j-1];
					cnt++;
				}
				dis[i][j]=cnt;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				cout<<i<<' '<<j<<':'<<dis[i][j]<<endl;
//			}
//		}
//		cout<<endl;
		for(int i=1;i<=n;i++){
			dp[i][i+1]=dis[i][i+1];
			if(dis[i][i+2]==0)dp[i][i+2]=0;
			else dp[i][i+2]=1;
		}
		for(int len=3;len<n;len++){
			for(int i=1;i+len<=n;i++){
				int j=i+len;
				for(int k=i+1;k<j;k++){
					if(dis[i][k]+dis[k][j]==dis[i][j])dp[i][j]+=dp[i][k]*dp[k][j];
					if(dp[i][j]>2)dp[i][j]=1e3;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cout<<i<<' '<<j<<": "<<dp[i][j]<<endl;
				if(dp[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int c,t,d;
int n,dp[N][N],ans,a[N],minn[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(dp,0,sizeof(dp));
		memset(minn,0x3f,sizeof(minn));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)	cin>>a[i];
		ans=0;
		for(int i=1;i<=n;i++)	minn[i][i]=0;
		for(int len=2;len<=n;len++){
			for(int l=1;l+len-1<=n;l++){
				int r=l+len-1;
				if(a[r]-a[l]<=d)	minn[l][r]=1;
				else{
					for(int k=r;k>=l;k--){
						minn[l][r]=min(minn[l][r],minn[l][k]+minn[k][r]);
					}
				}
			}
		}
		for(int len=2;len<=n;len++){
			for(int l=1;l+len-1<=n;l++){
				int r=l+len-1;
				if(minn[l][r]==1)	dp[l][r]=1;
				else{
					for(int k=r;k>=l;k--){
						if(minn[l][k]+minn[k][r]==minn[l][r])	dp[l][r]+=dp[l][k]*dp[k][r];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(dp[i][j]==2)	ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

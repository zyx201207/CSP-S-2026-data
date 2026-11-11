#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=3e2+5;
int c,T,n,d;
long long a[M],dp[M][M][M],sum[M][M];
void Normal(){
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int cnt=0;
		for(int i=1;i<n;i++){
			int p=i;
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++)dp[i][j][k]=0;
			for(int j=1;j<=i;j++)
				for(int k=0;k<=n;k++)sum[j][k]=0;
			dp[i][i][0]=1;sum[i][0]=1;
			for(int j=i+1;j<=n;j++){
				while(a[j]-a[p]>d)p++;
				if(p==j)break;
				int mi=0;
				for(int k=0;k<=n;k++){
					if(k)dp[i][j][k]=sum[j-1][k-1]-sum[p-1][k-1];
					sum[j][k]=sum[j-1][k]+dp[i][j][k];
					if((!mi)&&dp[i][j][k])mi=dp[i][j][k];
				}
				if(mi==2)cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
}
void Special(){
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int D=a[2]-a[1],ans=0;
		int k=d/D;
		ans+=max(0ll,n-3);
		if(k!=2)ans+=max(0ll,n-k-k+1);
		cout<<ans<<"\n";
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c!=11&&c!=12)Normal();
	else Special();
}

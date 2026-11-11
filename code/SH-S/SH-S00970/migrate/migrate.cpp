#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,c,t,d,dp[5][2000010],a[2000010],cnt,ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		cnt=1;ans=0;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}dp[1][1]=1;dp[1][2]=(a[2]-a[1])<=d;dp[1][3]=((a[3]-a[2])<=d)+((a[2]-a[1])<=d);
		for (int i=4;i<=n;i++){
			bool flag=0;
			for (int j=0;j<5;j++){
				dp[j][i]=0;
			}//dp[1][i]=lowerbound(a+1,a+i,a[i]-d)-a;
			if (a[i-1]-a[i-3]<=d && a[i]-a[i-2]<=d && a[i-2]-a[i-3]<=d && a[i]-a[i-1]<=d && a[i]-a[i-3]>d){
				dp[2][i]+=dp[1][i-3];
			}while (a[i]-a[cnt]>d){
				cnt++;
			}dp[2][i]+=dp[2][cnt];
			dp[1][i]=i-dp[2][i];
		}for (int i=1;i<=n;i++){
			ans+=dp[2][i];
		}cout<<ans<<"\n";
	}
}

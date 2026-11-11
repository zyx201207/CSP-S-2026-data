#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long mi,cnt;
}dp[5010][5010];
long long n,d,c,t,a[2000010],s[2000010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) dp[i][j]={0x3f3f3f3f3f3f3f3f,0};
		for(int i=1;i<=n;i++) cin>>a[i],dp[i][i]={0,1};
		for(int i=2;i<=n;i++) s[i]=s[i-1]+(a[i]-a[i-1]);
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				for(int k=r-1;k>=l&&(s[r]-s[k])<=d;k--){
					if(dp[l][k].mi+1<dp[l][r].mi) dp[l][r]={dp[l][k].mi+1,dp[l][k].cnt};
					else if(dp[l][k].mi+1==dp[l][r].mi) dp[l][r].cnt+=dp[l][k].cnt;
				}
				ans+=(dp[l][r].cnt==2); 
			} 
		} 
		cout<<ans<<'\n';
	}
	return 0;
}


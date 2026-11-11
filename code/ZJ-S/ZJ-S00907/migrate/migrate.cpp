#include<bits/stdc++.h>
using namespace std;
long long int a[2000007],dp[2000007],step[2000007];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int k=1;k<=n;k++){
			memset(dp,0,sizeof(dp));
			memset(step,0,sizeof(step));
			dp[k]=1;
			step[k]=0;
			for(int i=k+1;i<=n;i++){
				int mi;
				for(mi=i-1;mi>=k&&a[i]-a[mi]<=d;mi--);
				mi++;
				if(mi!=i) step[i]=step[mi]+1;
				for(int j=mi;step[j]==step[mi]&&j<i;j++) dp[i]+=dp[j];
				if(dp[i]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
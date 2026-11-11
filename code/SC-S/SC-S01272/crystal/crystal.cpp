#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[5003][5003]={0};
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	int a[n+11]={0};
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			f=1;
		}
	}
	int ans=0;
	if(f){
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			dp[i][i]=0;
			for(int j=i+1;j<=n;j++){
				dp[i][j]=dp[i][j-1]+((a[j]-a[j-1])*(j-i));
				if(dp[i][j]<=m){
					ans=max(ans,j-i+1);
				}
			}
		}
		cout<<ans;
	}
	else{
		int cha=a[2]-a[1];
		int ans=1;
		int zhi=0;
		for(int i=1;i<=122222222;i++){
			if(ans*cha+zhi<=m){
				zhi+=ans*cha;
				ans++;
			}
			else break;
			if(ans>=n) break;
		}
		cout<<ans;
	}
	return 0;
}
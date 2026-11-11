#include<iostream>
#include<cmath>
using namespace std;
#define int long long
int n,m,a[200010],ans=0,dp[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else{
		dp[1]=1;
		for(int i=2;i<=n;i++){
			dp[i]=a[i]&dp[i-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>1;j--){
				dp[j]=max(dp[j],dp[j-1]&a[i]);
			}
		}
		cout<<dp[m];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long dp[200005][21];
long long n,a[200005],ans=-1,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
				
			}
		}
		cout<<ans;
	}else if(m==n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			
		}
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n;i++){
			long long ansand=a[1];
			for(int j=1;j<=n;j++){
				if(j!=i){
					ans&=a[j];
				}
			}
			ans=max(ans,ansand);
		}
		long long ansand=a[2];
		for(int i=2;i<=n;i++){
			ansand&=a[i];
		}
		ans=max(ans,ansand);
		cout<<ans;
	}else if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dp[i-1][0]=a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			}
		}
		cout<<dp[n][m];
	}else{
		cout<<'0';
	}
	return 0;
}
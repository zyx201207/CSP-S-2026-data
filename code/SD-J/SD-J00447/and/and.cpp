#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],dp[N],s,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	dp[1]=a[1];
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++) dp[i]=0;
		for(int j=i+1;j<=n;j++){
			    dp[j]=max(dp[j-1],dp[j]&a[j]);
		}
		ans=max(ans,dp[n]);
	}
	cout<<ans;
	return 0;
}

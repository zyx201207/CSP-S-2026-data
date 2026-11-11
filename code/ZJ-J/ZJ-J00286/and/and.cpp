#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,m;
int a[N],dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=2;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
		if(i==1) dp[1]=a[1];
		dp[1]=max(a[i],dp[1]);
	}
	cout<<dp[m];
	return 0;
}

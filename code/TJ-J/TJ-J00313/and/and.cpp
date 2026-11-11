#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,dp[200005]={};
	cin>>n>>m;
	int a[200005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dp[i]=max(dp[i],a[i]&a[j]);
			}
		}
		sort(dp+1,dp+1+n);
		cout<<dp[n];
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(i==1){
				dp[1]=a[i];
			}else{
				dp[1]&=a[i];
			}
		}
		cout<<dp[1];
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

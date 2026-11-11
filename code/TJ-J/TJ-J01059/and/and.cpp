#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(j==1){
				dp[j]=max(dp[j],a[i]);
			}
			else{
			   	dp[j]=max((dp[j-1]&a[i]),dp[j]);
			}
		}
	}
	cout<<dp[m];
	return 0;
}

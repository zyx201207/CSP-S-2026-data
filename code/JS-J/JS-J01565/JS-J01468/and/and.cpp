#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>2;j--){
			dp[j]=max(dp[j],a[i]&dp[j-1]);
		}
		for(int j=1;j<i;j++){
			dp[2]=max(dp[2],a[i]&a[j]);
		}
	}
	cout<<dp[m];
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[500005],dp[1000000]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long maxl=0;
	for(int i=2;i<=n;i++){
		dp[i]=(i-1)*(a[i]-a[i-1])+dp[i-1];
		if(dp[i]<=m){
			maxl=i;
		}
		else{
			break;
		}
	}
	cout<<maxl;
	return 0;
} 

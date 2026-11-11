#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],dp[500005][2],ans,c;
bool b;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		if(a[2]-a[1]<=m)cout<<2;
		else cout<<1;
		return 0;
	}
	c=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=c){
			b=1;
			break;
		}
	}
	if(!b){
		long long s=0;
		for(int i=1;i<=n-1;i++){
			s+=i;
			if(s*c>m){
				cout<<i<<endl;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	dp[1][0]=ans=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]>m){
			dp[i][0]=1;
			continue;
		}
		if(dp[i-1][0]*(a[i]-a[i-1])+dp[i-1][1]<=m){
			dp[i][0]=dp[i-1][0]+1;
			dp[i][1]=dp[i-1][0]*(a[i]-a[i-1])+dp[i-1][1];
		}
		else{
			long long s=0;
			int j=i-1;
			while(j>0&&s+a[i]-a[j]<=m){
				s+=a[i]-a[j];
				j--;
			}
			dp[i][0]=i-j;
			dp[i][1]=s;
		}
		ans=max(ans,dp[i][0]);
	}
	cout<<ans;
	return 0;
} 

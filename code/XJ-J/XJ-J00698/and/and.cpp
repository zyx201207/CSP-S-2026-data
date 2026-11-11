#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],m,dp[100005],cnt=0,maxn=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
			cin>>a[i];
			maxn=max(maxn,a[i]);
		}
	int tt=1,tt1=1;
	for(int i=1;i<=21;i++){
		tt*=2;
	}
	for(int i=1;i<=11;i++){
		tt1*=2;
	}		
	if(n<=2000||maxn>tt||maxn<tt1){
		 
		dp[0]=1;
		for(int i=0;i<=31;i++){
			dp[0]=dp[0]*2+1;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i;j>=cnt+1;j--){
				if((a[i]&dp[j-1])>dp[j])	dp[j]=dp[j-1]&a[i];
				
				if(dp[j]==maxn)	cnt=j;
			}
		}
		cout<<dp[m];
	 } 
	else{
		if(m==n-1){
			dp[0]=a[1];
			for(int i=1;i<=m;i++){
				dp[i]=dp[i-1]&a[i];
			}
			cout<<dp[m];
		}
		else{
			int num=1;
			for(int i=maxn;i>=1;i/=2){
				num++;
			}
			for(int i=num;i>m;i--){
				cout<<1;
			}
		}
		
	} 
	return 0;
} 

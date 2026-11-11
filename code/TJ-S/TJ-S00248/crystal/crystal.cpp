#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>dp[i];
	sort(dp+1,dp+n+1);
	if(m==0){//0
		int mx=0,t=0;
		for(int i=1;i<=n;i++){
			t=0;
			for(int j=1;j<=n;j++){
				if(dp[i]==dp[j])t++;
			}
			mx=max(mx,t);
		}
		cout<<mx;
		return 0; 
	}
	if(dp[1]==dp[2]-1&&dp[2]==dp[3]-1&&dp[3]==dp[4]-1){//a[i]=i
		long long c=0;
		for(int i=1;i<=n;i++)if(m-i>=0)c++;
		cout<<c;
		return 0;
	}
	else{
		bool pd=1;
		for(int i=1;i<n;i++)if(dp[i]!=dp[i+1])pd=0;
		if(pd)cout<<n;
		else{
			int mi=(n/2)+1,t=m;
			int md=dp[mi];
			int x=0,y=0;
			for(int i=1;i<mi;i++){
				if(md-dp[i]<=t){
					x++;
					t-=md-dp[i];
				}
			}
			for(int i=mi;i<=n;i++){
				if(dp[i]-md<=t){
					y++;
					t-=md-dp[i];
				}
			}
			cout<<max(x,y)+1;
		}
	}
	return 0;
} 

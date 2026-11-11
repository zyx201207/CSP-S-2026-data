#include<bits/stdc++.h>
using namespace std;
int c,q;
int n;
unsigned long long d;
unsigned long long x[2000005];
int dp[2000005];

int work(int i){
	if((x[i+3]-x[i+1])<=d && ((x[i+3]-x[i+2])<=d && (x[i+2]-x[i])<=d) && (x[i+3]-x[i])>d)
		return 1;
	return 0;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--){
		memset(dp,0,sizeof(dp));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=n-3;i>=1;i--){
			if(x[i]-x[i+1]<=d && x[i]-x[i+2]<=d){
				dp[i]=dp[i+1]+work(i);
			}else if(x[i]-x[i+1]<=d){
				dp[i]=dp[i+1]*2+work(i);
			}else{
				dp[i]=dp[i+1];
			}
		}
		cout<<dp[1]<<"\n";
	}
	return 0;
}
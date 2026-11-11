#include<bits/stdc++.h>
using namespace std;
int n,d,x[2000005],dp[2000005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		dp[1]=0;
		for(int i=2;i<=n;i++){
			int p=lower_bound(x+1,x+n+1,x[i]-d)-x;
			if(i-p+1>2)dp[i]=0;
			else dp[i]=dp[i-1]+(i-p+1);
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
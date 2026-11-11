#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000011],cnt,dp[2000011];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for (long long i=1;i<=n;i++){
			cin>>a[i];
			dp[i]=0;
		}
		int q=n;
		for (long long i=1;i<=n;i++){
			if (a[i+1]-a[i]>d){
				q=i;
			}
		}
		if (d>=q-1){
			cout<<0<<endl;
			continue;
		}
		dp[d+2]=1;
		for (long long i=d+3;i<=q;i++){
			if (i>d+2)
				dp[i]+=q/d;
			else if ((i-1)%d==0){
				dp[i]=dp[i-1];
			}
		}
		cout<<dp[q];
	}
	return 0;
}

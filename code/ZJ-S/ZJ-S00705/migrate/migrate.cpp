#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d,x[2000005],dp[2000005]={},ans=0;
		for(int i=1;i<=n;++i)cin>>x[i];
		dp[0]=1;
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)
				if(x[j]-x[i]<=d)dp[j]+=dp[i];
		for(int i=1;i<=n;++i)
			if(dp[i]==2)++ans;
		cout<<ans<<"\n";
	}
	return 0;
}
//mima:Oct31==Dec25?

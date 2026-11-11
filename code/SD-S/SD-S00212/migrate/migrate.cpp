#include <bits/stdc++.h>
using namespace std;
long long x[2000010],dp[2000010];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		long long n,d;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		long long ans=0;
		for(long long i=1;i<=n;i++){
			map<long long,bool>mp;
			int d=lower_bound(x+1,x+n+1,x[i]-d)-x;
			for(long long j=i;j>=max(0,d);j--){
				if(mp.count(dp[j]+x[i]-x[j]))ans++;
				mp[dp[j]+x[i]-x[j]]=1;
				dp[i]=min(dp[i],dp[j]+x[i]-x[j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000010],dp[5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>a[i];
		if(a[2]-a[1]>d){
			cout<<"0\n";
			continue;
		}
		long long mx=d/(a[2]-a[1]);
		long long ans=0;
		for(long long i=1;i+2*mx-1<=n;i++){
			ans+=(n-i-2*mx+1)/mx+1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
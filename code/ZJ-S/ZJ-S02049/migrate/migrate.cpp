#include<bits/stdc++.h>
using namespace std;
int ans,c,T,n,dp[2000010],cnt[2000010];
long long d,a[2000010];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		a[n+1]=0x3f3f3f3f3f3f3f3f;
		for(int i=n;i>=1;i--){
			int x=upper_bound(a+i,a+n+2,a[i]+d)-a;
			dp[i]=dp[x-1]+1;
			int y=lower_bound(dp+i,dp+n+1,dp[i]-1)-dp;
			cnt[i]=(x-y+1);
			if(cnt[i]==2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}


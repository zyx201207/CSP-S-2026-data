#include<bits/stdc++.h>
using namespace std;
int cc,t,n,ans;
long long d,a[2000006],c[2000006],s[2000006],dp[2000006],cnt[2000006];
int pd(int x,int y){
	for(int i=x+1;i<=y;i++) dp[i]=1e9,cnt[i]=0;
	cnt[x]=1,dp[x]=0;
	for(int i=x+1;i<=y;i++)
		for(int j=x;j<i;j++) if(a[i]-a[j]<=d)
			if(dp[j]+1==dp[i]) cnt[i]+=cnt[j];
			else if(dp[j]+1<dp[i]) dp[i]=dp[j]+1,cnt[i]=cnt[j];
	if(cnt[y]==2) return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>cc>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans+=pd(i,j);
		cout<<ans<<'\n';
	}
	return 0;
}
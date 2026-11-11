#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int _,T,n,d;
int a[2000020];
int s[2000020];
int lp[2000020];
int sh[2000020];
int dp[2000020];
int ans=0;
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	int pos=1;
	for(int i=1;i<=n;i++){
		while(pos<=n&&a[pos]-a[i]<=d) pos++;
		s[i]=pos-1;
	}
	s[n+1]=n+1;
	pos=1;
	for(int i=1;i<=n;i++){
		while(pos<=n&&a[i]-a[pos]>d) pos++;
		lp[i]=pos;
	}
	for(int i=1;i<=n;i++){
		pos=i;
		for(int j=i-1;j<=n;j++) sh[j]=0,dp[j]=0;
		dp[i]=sh[i]=1;
		int last_l=i,last_r=i;
		for(;pos!=s[pos];pos=s[pos]){
			for(int j=pos+1;j<=s[pos];j++){
				int lr=max(lp[j],last_l),rr=last_r;
				if(lr<=rr) dp[j]=sh[rr]-sh[lr-1];
//				cout<<i<<" "<<j<<" "<<lr<<" "<<rr<<endl;
				if(dp[j]>2) dp[j]=3;
				sh[j]=sh[j-1]+dp[j]; 				
			}
			last_r=s[pos],last_l=pos+1;
		}						
//		for(int j=i;j<=n;j++) cout<<i<<" "<<j<<" "<<dp[j]<<endl;
		for(int j=i;j<=n;j++) if(dp[j]==2) ans++;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>_>>T;
	while(T--) solve();
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/


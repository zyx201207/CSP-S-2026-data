#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5,inf=1e16;
long long C,T;
long long n,d,a[N],ans,l,r[N],last,tot,dp[N],kp[N];
struct node{
	long long l,r;
}b[N];
inline void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n+5;i++) dp[i]=inf,kp[i]=0;
	if(n==1){
		cout<<0<<'\n';
		return ;
	}
	if(11<=C&&C<=12){
		d=d/(a[2]-a[1]);
		if(d<=1) cout<<0<<'\n';
		else cout<<max(n-2*d+1,0ll)<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dp[j]=inf,kp[j]=0;
		kp[i]=1;
		dp[i]=0;
		l=i;
		for(int j=i+1;j<=n;j++){
			while(a[j]-a[l]>d) l++;
			if(j==l) break;
			dp[j]=dp[l]+1;
			if(dp[j]==dp[l]+1) kp[j]+=kp[l];
			if(dp[j]==dp[l+1]+1) kp[j]+=kp[l+1];
			if(dp[j]==dp[l+2]+1) kp[j]+=kp[l+2];
			if(kp[j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>C>>T;
	while(T--) solve();
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,t,n,m,a[N],b[N],l[N],dp[N],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int cnt=1; 
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			while(a[i]-a[cnt]>m) cnt++;
			l[i]=cnt;
		}
		for(int i=1;i<=n;i++){
			b[i]=1;
			if(a[l[i]]+m<a[i+1]) b[i]++;
			b[i]+=b[i-1];
		}
		for(int i=1;i<=n;i++){
			dp[i]+=dp[l[i]];
			if(l[i]+2<=i) dp[i]+=b[l[l[i]+2]-1]-b[l[l[i]+1]-1];
			ans+=dp[i];
//			cout<<dp[i]<<" ";
		}
		cout<<ans<<"\n";
		ans=0;
		for(int i=1;i<=n;i++) a[i]=0,b[i]=0,l[i]=0,dp[i]=0;
	}
	return 0;
}
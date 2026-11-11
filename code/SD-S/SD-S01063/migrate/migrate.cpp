#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,x[N],dp[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(dp,0,sizeof dp);
		if(c==11||c==12){
			for(int i=1;i<=n;i++) cin>>x[i];
			int ans=max(0ll,n-d-1);
			cout<<ans<<'\n';
			continue;
		}int ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>=4){
				int pos=i-(lower_bound(x+1,x+i+1,x[i]-d)-x);
				if(pos!=2) continue;
				dp[i]=dp[i-1]+dp[i-2]+1;
			//	cout<<"dp:"<<dp[i]<<'\n';
				ans+=dp[i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

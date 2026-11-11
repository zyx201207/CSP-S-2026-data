#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d,l,r,a[N],dp[N],sum[N];
queue<int> q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j) dp[j]=n+10,sum[j]=0;
			dp[i]=0; sum[i]=1;
			for(int j=i+1;j<=n;++j){
				for(int k=j-1;k>=i;--k){
					if(a[j]-a[k]>d) break;
					if(dp[k]+1<dp[j]) dp[j]=dp[k]+1,sum[j]=sum[k];
					else if(dp[k]+1==dp[j]) sum[j]+=sum[k];
				}
				if(sum[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}


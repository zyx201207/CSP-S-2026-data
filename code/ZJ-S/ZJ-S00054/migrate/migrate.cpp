#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,inf=4e18;
int c,T,n,d,a[N],t[N],dp[N],dp2[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		int ans=0,ok=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]!=d-1&&i!=1) ok=0;
		}
		if(ok){
			cout<<(n-1)/d<<'\n';
			continue;
		}
		int x=a[1],cnt=0,sum=0;
		for(int i=1;i<=n;i++) dp[i]=dp2[i]=0;
		dp[1]=dp2[1]=1;
		for(int i=2;i<=n;i++){
			if(a[i]>x){
				if(sum==2){
					if(dp[i-3]) ans++,dp2[i]=1;
				}
				else if(sum==1){
					dp[i-1]=1;
					if(dp2[i-2]) ans++;
				}
				if(a[i-1]+d<a[i]){
					t[i]=0;
					cnt=0;
					dp[i]=1;
					x=a[i];
					sum=0;
				}
				else t[i]=++cnt,x=a[i-1]+d,sum=1;
			}
			else t[i]=cnt,sum++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

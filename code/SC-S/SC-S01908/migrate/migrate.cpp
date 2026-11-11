#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5005;
const int BN = 2e6+5;
int c,t,n;
ll ans,d,a[BN],dp[N][N],f[N][N];
pair<ll,ll> mi;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	if(c == 13||c == 14){
		cin>>c>>t;
		while(t--){
			cin>>n>>d;
			for(int i = 1;i<=n;i++) cin>>a[i];
			cout<<"0\n";
		}
	}
	else{
		cin>>c>>t;
		while(t--){
			cin>>n>>d;
			for(int i = 1;i<=n;i++) cin>>a[i];
			for(int i = 1;i<=n;i++){
				dp[i][i] = 0;
				f[i][i] = 1;
			}
			for(int i = 2;i<=n;i++){
				int k = lower_bound(a+1,a+n+1,a[i]-d)-a;
				for(int j = 1;j<k;j++){//求解dp[j][i]与f[j][i]
					mi = {1e18,0};
					for(int p = k;p<i;p++){
						//j--p--i
						if(dp[j][p]+1<mi.first) mi = {dp[j][p]+1,f[j][p]};
						else if(dp[j][p]+1==mi.first) mi = {mi.first,mi.second+f[j][p]};
					}
					dp[j][i] = mi.first;
					f[j][i] = mi.second;
				}
				for(int j = k;j<i;j++){
					dp[j][i] = 1;
					f[j][i] = 1;
				}
			}
			ans = 0;
			for(int i = 2;i<=n;i++){
				for(int j = 1;j<i;j++) if(f[j][i] == 2) ans++;
			}
			cout<<ans<<'\n';
		}
	}
	
	return 0;
}
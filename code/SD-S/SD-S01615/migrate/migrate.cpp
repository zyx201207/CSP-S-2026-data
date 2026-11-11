#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,d,a[2000100],f[2000100],dp[2000100];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t,c;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ll ans=0;
		memset(f,0x3f,sizeof f);
		for(int k=1;k<=n;k++){
			memset(dp,0,sizeof dp);
			f[k]=0;
			for(int i=k+1;i<=n;i++){
				f[i]=1e18;
				for(int j=i-1;j>=k;j--){
					if(a[i]-a[j]>d)break;
					if(f[i]>f[j]+1){
						f[i]=f[j]+1;
						dp[i]=0; 
					}
					if(f[i]==f[j]+1){
						dp[i]++;
					}
				}
			}
			for(int i=k+1;i<=n;i++){
				if(dp[i]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


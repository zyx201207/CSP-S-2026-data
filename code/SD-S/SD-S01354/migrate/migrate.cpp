#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5,inf=1e18,mod=1e9+7;
ll c,t,n,k,a[N],d[N];
signed main () {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ll ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			d[i]=d[i-1]+a[i]-a[i-1];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(d[j]-d[i]<=k) continue;
				ll t=(d[j]-d[i])/k+1;
				if(j-i-1==t&&t%2==0){
				//	cout<<i<<' '<<j<<' '<<t<<'\n';
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
ll c,t,n,m,a[N];
map<ll,ll> f[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for (ll i=1;i<=n;i++){
			cin>>a[i];
			f[i][i]=0;
		}
		ll ans=0;
		for (ll l=2;l<=n;l++){
			for (ll i=1;i+l-1<=n;i++){
				ll j=i+l-1,cnt=0;
				if(a[j]-a[i]<=m) f[i][j]=1;
				else f[i][j]=0x3f3f3f3f;
				for (ll k=i+1;k<j;k++){
					if(f[i][j]==f[i][k]+f[k][j]){
						cnt++;
					}
					if(f[i][j]>f[i][k]+f[k][j]){
						cnt=1;
						f[i][j]=f[i][k]+f[k][j];
					}
				}
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
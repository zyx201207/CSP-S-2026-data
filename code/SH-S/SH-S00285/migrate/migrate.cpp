#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,d;
ll x[2000005],f[2000005];
queue<ll> q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>x[i];
		ll ans=0;
		bool fl;
		for(ll i=1;i<=n;i++){
			fl=0;
			for(ll j=i;j<=n;j++){
				f[i]=0;
			}
			ll pre=i;
			for(ll j=i+1;j<=n;j++){
				while(x[j]-d>x[pre]&&pre<j)pre++;
				f[j]=f[pre]+1;
				if(j-pre>=2&&f[pre]==f[pre+1]&&f[pre+1]!=f[pre+2]){
					if(fl)break;
					fl=1;
					ans++;
					continue;
				}
				if(j-pre==0)break;
				if(j-pre==1&&fl){
					ans++;
					continue;
				}
				if(j-pre>2)break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

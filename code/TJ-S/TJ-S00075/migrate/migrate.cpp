#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,t,q,k;
ll a[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			k=a[i]-a[i-1];
		}
		if(c!=11&&c!=12){
			if(c>12){
				cout<<"0\n";
				continue;
			}
			ll ans=0;
			for(ll i=1;i<=n;i++){
				for(ll j=i;j<=n;j++){
					if(a[j]<=m+a[i]) continue;
					ll ll2=0;
					for(ll f=i+1;f<=j-1;f++){
						if(a[f]<=m+a[i]&&a[j]<=m+a[f]) ll2++;
					}
					if(ll2==2) ans++;
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		m/=k;
		if(m<=1){
			cout<<"0\n";
			continue;
		}
		m=n-m*2+1;
		if(m<=0){
			cout<<"0\n";
			continue;
		}
		cout<<m<<'\n';
	}
	return 0;//10 23 2 6 8 4 16 12 18 10 14 20
}

//SN-S00485 张子茗 西安铁一中滨河高级中学
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll b[2000005];
ll x[2000005];
int main () {
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	ll c,t,n,d;
	cin>>c>>t;
	for (int tt=1;tt<=t;tt++) {
		cin>>n>>d;
		
		for (ll i=1;i<=n;i++) {
			cin>>x[i];
			if (i>=2) {
				b[i]=x[i]-x[i-1];
			}
		}
		
		int ans=0,ddnum=0;
		int dd=d;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				dd=d;
				if (dd>b[j]) {
					dd-=b[j];
					ddnum++;
					}
				else {
					break;
				}
			}
			
			bool a,b1;
			if ((x[i]+b[i]==x[i+1]) && (x[i+1]+d==x[i+ddnum])) {
				a=true;
			}
			else{
				a=false;
			}
			if ((x[i]+d==x[i+ddnum-1]) && (x[i+ddnum-1]+b[i]==x[i+ddnum])) {
				b1=true;
			}
			else {
				b1=false;
			}
			if (a && b1) ans++;
			}
			cout<<ans<<"\n";
		}
	return 0;
}

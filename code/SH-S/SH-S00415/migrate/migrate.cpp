#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+7;

int c,t,n;
ll d,x[N],ans;

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n==1) {cout<<0<<'\n';continue;}
		if(c==11||c==12) {
			ll l=x[2]-x[1],k=d/l;
			if(k<2)cout<<0<<'\n';
			else cout<<max(0ll,n-2*k+1)<<'\n';
		}
		if(c==13||c==14) {
			for(int i=1;i<=n;i++) {
				int j=upper_bound(x+1,x+n+1,x[i]+d)-x;
				if(x[i]+d>=x[n])j=n+1;
				if(i>=j-2)continue;
				int r=upper_bound(x+1,x+n+1,x[j-2]+d)-x;
				if(x[j-2]+d>=x[n])r=n+1;
				int l=upper_bound(x+1,x+n+1,x[j-3]+d)-x;
				if(x[j-3]+d>=x[n])l=n+1;
				ans+=r-l;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}

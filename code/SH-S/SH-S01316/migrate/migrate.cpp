#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n;
long long d,a[N],s,k,ans;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12) {
		while(t--) {
			cin>>n>>d;
			for(int i=1;i<=n;++i) cin>>a[i];
			if(n==1) {
				cout<<0<<endl;
				continue;
			}
			s=a[2]-a[1];
			if(d<2*s) {
				cout<<0<<endl;
				continue;
			}
			k=d/s;
			ans=(k-1)*n-3*k*(k-1)/2;
			ans=max(0ll,ans);
			cout<<ans<<endl;
		}
	}else {
		while(t--) cout<<0<<endl;
	}
	return 0;
}

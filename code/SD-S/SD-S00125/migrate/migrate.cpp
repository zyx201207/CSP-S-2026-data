#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
int c,t,n,d,x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		sort(x+1,x+1+n);
		if(c==11||c==12) {
			if(x[1]==x[2]||d<(x[2]-x[1])) cout<<"0\n";
			else cout<<max(n-d/(x[2]-x[1])*2+1,0ll)<<"\n";
		}
		else if(c==13||c==14) {
			int ans=0;
			for(int i=1;i<=n;i++){
				int p=upper_bound(x+1,x+1+n,x[i]+d)-x,q=lower_bound(x+1,x+1+n,x[i]-d)-x;
				ans+=n-p+q;
			}
			cout<<ans/2<<"\n";
		}
	}
	return 0; 
}

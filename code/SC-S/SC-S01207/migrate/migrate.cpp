#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10;
ll c,t,n,d,x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		ll ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int l=1;l<=n-3;l++) {
			for(int r=l+3;r<=n;r++) {
				bool c=false;
				ll cur=0,cur2=0,cnt=0,cnt2=0,turn=0;
				for(int k=l;k<r;k++) {
					if(abs(x[k+1]-x[k])>d) {
						c=true;
						break;
					} 
					if(turn==0) {
						if(cur<=d) cur+=abs(x[k+1]-x[k]);
						else cnt++,cur=0;
					} else {
						if(cur2<=d) cur2+=abs(x[k+1]-x[k]);
						else cnt2++,cur2=0;
					}
					turn^=1;
				}
				if(!c&&cnt==r-l&&cnt2==r-l) ans++;	
			}
		} 
		cout<<ans<<"\n";
	}
	return 0;
}
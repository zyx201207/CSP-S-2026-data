#include <bits/stdc++.h>
#define int long long
using namespace std;
int x[2000005],a[2000005],c[2000005];
signed main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cc,t;
	cin>>cc>>t;
	while(t--) {
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++) {
			a[i]=lower_bound(x,x+n+1,x[i]-d)-x;
			int k=upper_bound(x,x+n+1,x[i]+d)-x-1;
			c[i]=k;
		}
		int ans=0;
		for(int i=1;i<=n;i++) {
			int k=c[i]-1,p=c[i],s=0,ss=0;
			int cnt=1;
			int ls=i,lss=c[i];
			for(int j=i-1;j>=1;j--) {
				if(x[ls]-x[j]<=d&&x[ls+1]-x[j]>d&&x[lss]-x[ls]<=d&&x[lss]-x[ls-1]>d) cnt++;
				if(j==a[ls]) {
					if(a[ls]==a[ls+1]) break;
					lss=ls;
					ls=a[ls];
				}
			}
			for(int j=c[i]+1;j<=n;j++) {
				if(a[j]==k&&s==ss) ans+=cnt;
				if(j==c[p]) p=c[p],s++;
				if(j==c[k]) {
					if(a[c[k]]<k) break;
					k=c[k],ss++;
				}
			}
		}
		for(int i=1;i<=n;i++) a[i]=c[i]=0;
		cout<<ans<<endl;
	}
	return 0;
}

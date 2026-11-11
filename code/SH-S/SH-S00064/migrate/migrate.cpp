#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
int nx[2000005];
int ll[2000005];
int lr[2000005];
int rl[2000005];
int rr[2000005];
int tp[2000005]; 
int pr[2000005];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int d;
		cin>>d;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		for(int i=0;i<=n+2;i++) {
			pr[i]=ll[i]=rr[i]=lr[i]=rl[i]=tp[i]=nx[i]=0;
		}
		if(n<=3) {
			cout<<0<<'\n';
			continue;
		}
		a[n+1]=5e18;
		a[0]=-5e18;
		for(int i=2;i<=n-2;i++) {
			if(a[i]+d<=a[i+1]) continue;
			int pos=n+1;
			int l=i+2,r=n;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(a[mid]>a[i-1]+d) {
					r=mid-1;
					pos=mid;
				}
				else l=mid+1;
			}
			rl[i]=pos;
			pos=i+1;
			l=i+2,r=n;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(a[mid]<=a[i]+d) {
					l=mid+1;
					pos=mid;
				}
				else r=mid-1;
			}
			rr[i]=pos;
			pos=i;
			l=1,r=i-1;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(a[mid]>=a[i+1]-d) {
					r=mid-1;
					pos=mid;
				}
				else l=mid+1;
			}
			ll[i]=pos;
			pos=0;
			l=1,r=i-1;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(a[mid]<a[i+2]-d) {
					l=mid+1;
					pos=mid;
				}
				else r=mid-1;
			}
			lr[i]=pos;
			if(ll[i]>=i||rr[i]<=i+1||a[rr[i]]-a[ll[i]]<=d) {
				tp[i]=0;
			}
			else if(ll[i]>lr[i]||rl[i]>rr[i]) {
				tp[i]=2;
			}
			else tp[i]=1;
		}
		int ans=0;
		int lst=n+1;
		for(int i=n-2;i>=2;i--) {
			nx[i]=lst;
			if(tp[i]) lst=i;
			if(a[i+1]-a[i]>d) {
				lst=i;
				rr[i]=i+1;
			}
		}
		rr[n+1]=n+1;
		lst=0;
		for(int i=2;i<=n-2;i++) {
			pr[i]=lst;
			if(tp[i]) lst=i;
			if(a[i]-a[i-1]>d) {
				lst=i;
				ll[i]=i-1;
			}
		}
		ll[0]=0;
		for(int i=2;i<=n-2;i++) {
			if(tp[i]==1) {
				ans+=(lr[i]-ll[pr[i]])*(rr[nx[i]]-rl[i]);
			}
		}
		cout<<ans<<'\n';
	}  
	return 0;
}

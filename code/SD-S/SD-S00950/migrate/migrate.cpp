#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,C,T,a[2000009];
int aa(int l,int r,int x) {
	int ans;
	while(l<=r) {
		int mid=(l+r)/2;
		if(x-a[mid]<=d) ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) cin>>a[i];
		int ans=0;
		for(int i=1; i<n; i++) {
			int r=i,l=i,f=0,r1=-1,r2=-1;
			while(r<n) {
				r=upper_bound(a+1,a+n+1,a[l]+d)-a-1;
				if(l-1>=i) r1=upper_bound(a+1,a+n+1,a[l-1]+d)-a-1;
				if(l-2>=i) r2=upper_bound(a+1,a+n+1,a[l-2]+d)-a-1;
				if(r1==r&&r1==r2) break;
				if(r1==r&&f) break;
				if(r1==r) f=1;
				if(r==l) break;
				if(r1>l&&l!=i) ans+=r1-l;
				l=r;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

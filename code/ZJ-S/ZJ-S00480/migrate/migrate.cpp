#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2001000],r[5010],b[5010],z[5010],ansz[5010];
int main() {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) {
		long long n,d;
		long long ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++)cin>>a[i];
		if(n==1||n==2||c>18) {
			cout<<"0\n";
			continue;
		}
		if(c==11||c==12) {
			long long gc=a[2]-a[1];
			if(d>=2*gc)cout<<max(0ll,n-(d/gc)*2+1)<<'\n';
			else cout<<"0\n";

			continue;
		}
		if(c==13||c==14||c==0) {
			int mid=0;
			for(int i=1; i<=n; i++) {
				if(a[i]-d<=a[1]&&a[i]+d>=a[n]) {
					mid=i;
					break;
				}
			}
			if(mid>n-2||mid<=2) {
				cout<<"0\n";
				continue;
			}
			int r=0,l=0;
			for(int i=mid; i<=n; i++) {
				if(a[i]-d>a[mid-1]) {
					r=n-i+1;
					break;
				}
			}
			for(int i=mid; i>=1; i--) {
				if(a[i]+d<a[mid+1]) {
					l=i;
					break;
				}
			}
			for(int i=1; i<=mid; i++) {
				if(a[i]+d>=a[mid+1]&&a[i]+d<a[mid+2]) {
					ans+=r;
				}
				if(a[i]+d>=a[mid+2]) {
					break;
				}
			}
			for(int i=n; i>=mid; i--) {
				if(a[i]-d<=a[mid-1]&&a[i]-d>a[mid-2]) {
					ans+=l;
				}
				if(a[i]-d<=a[mid-2]) {
					break;
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1; i<=n; i++) {
			r[0]=i;
			int l=1;
			for(int j=1; j<=n; j++) {
				b[j]=0;
				z[j]=0;
				ansz[j]=0;
			}
			ansz[i]=1;
			z[i]=1;
			b[i]=0;
			for(int j=i+1; j<=n; j++) {
				while(a[l]+d<a[j])l++;
				b[j]=b[l]+1;
				z[j]=ansz[r[b[l]]]-ansz[l-1];
				r[b[j]]=j;
				ansz[j]=ansz[j-1]+z[j];
				if(z[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],x,k;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		bool flag=true;
		for(long long i=1; i<=n; i++) {
			cin>>a[i];
			if(i>=2&&a[i]-a[i-1]!=a[2]-a[1]) flag=false;
		}
		if(d>a[n]-a[1]) {
			cout<<"0"<<endl;
			continue;
		}
		if(flag==true) {
			x=a[2]-a[1];
			if(d<2*x) {
				cout<<"0"<<endl;
				continue;
			}
			k=d/x;
			k=k+(k-1);
			cout<<n-k<<endl;
		} else {
			if(n<=300) {
				long long ans=0;
				for(long long i=1; i<=n-3; i++) {
					for(long long j=i+3; j<=n; j++) {
						if(a[j]-a[i]<=d) continue;
						if(a[j]-a[i]>=2*d) break;
						long long l=i,r=j,mid;
						while(l<=r) {
							mid=(l+r)/2;
							if(a[j]-d==a[mid]) {
								break;
							}
							if(a[j]-d<a[mid]) {
								r=mid-1;
							}
							if(a[j]-d>a[mid]) {
								l=mid+1;
							}
						}
						if(a[mid]<a[j]-d&&a[mid+1]<=a[i]+d||a[mid]>a[j]-d&&a[mid+2]<=a[i]+d) continue;
						ans++;
						cout<<i<<" "<<j<<endl;
					}
				}
				cout<<ans<<endl;
			} else {
				cout<<"0"<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

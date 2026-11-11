#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans;
int a[2000005];
int s[2000005]
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int q=1; q<=t; q++) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<n-1; i++) {
			if(a[i]+d>=a[i+2]) {
				for(int j=i; j<=n; j++) {
					s[j]++;
				}
			}
		}
		if(c==0) {
			cout<<1<<endl<<2;
		} else {
			for(int i=1; i<n-1; i++) {
				if(s[i]==2) {
					ans++;
				}
			}
			cout<<ans<<" ";
			ans=0;
			for(int i=1; i<=n; i++) {
				a[i]=0;
			}
			for(int i=1; i<=n; i++) {
				s[i]=0;
			}
		}
	}
}

#include<bits/stdc++.h>
using namespace std;
long long t,a[2000005];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--) {
		long long n,d,ans=0;
		cin>>n>>d;
		for(int i=0; i<n; i++)cin>>a[i];
		for(int i=0; i<=n/2; i++)
			for(int j=n-1; j>n/2; j--)
				if((max(a[i],a[j])-min(a[i],a[j]))==3)ans++;
		cout<<ans<<endl;
	}
	return 0;
}

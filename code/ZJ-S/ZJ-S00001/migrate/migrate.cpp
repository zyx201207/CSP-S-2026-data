#include<bits/stdc++.h>
using namespace std;
const int MN=2e6+5;
int n,c;
long long d,a[MN],to[MN],from[MN],f[MN],b[MN];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>c>>t;
	while(t--) {
		long long ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++)cin>>a[i];
		int p=2;
		for(int i=1; i<=n; i++) {
			while(p<=n&&a[p]-a[i]<=d)p++;
			to[i]=p-1;
		}
		p=n-1;
		for(int i=n; i>=1; --i) {
			while(p>0&&a[i]-a[p]<=d)p--;
			from[i]=p+1;
		}
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		for(int i=1; i<=n; i++) {
			if(to[to[i]-1]>to[i]) {
				for(int j=to[to[i]-2]+1; j<=to[to[i]-1]; j++)
					b[i]++,f[j]++,ans++;
			}
		}
//		for(int i=1; i<=n; i++)
//			cout<<f[i]<<" ";
		for(int i=n; i>=0; i--)
			if(from[i]==i-1&&to[i-1]==i)
				ans+=b[i],b[i-1]+=b[i];
		for(int i=1; i<=n+1; i++)
			if(from[i+1]==i&&to[i]==i+1)
				ans+=f[i],f[i+1]+=f[i];
//		for(int i=1; i<=n; i++)
//			ans+=f[i]*(to[i]-i);
		//cout<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}

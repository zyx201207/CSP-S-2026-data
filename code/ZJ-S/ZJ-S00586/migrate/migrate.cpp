#include<bits/stdc++.h>
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,a[N],e[N];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ioi;
	cin>>c>>t;
	if(c>=11 && c<=12) {
		while(t--) {
			c=0;
			cin>>n>>d;
			for(int i=1; i<=n; i++) {
				cin>>a[i];
				if(a[i]-a[i-1]>d) e[++c]=i-1;
			}
			int dis=a[2]-a[1];
			for(int i=1; i<=c; i++) {
				if(e[i]-e[i-1]<3) continue;
				for(int j=e[i-1]+1; j<=e[i]; j++) {
					for(int k=j+1; k<=e[i]; k++) {
						if(d>=2*dis) cout<<n-3;
					}
				}
			}
		}
	}
	return 0;
}

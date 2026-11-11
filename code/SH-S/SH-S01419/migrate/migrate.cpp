#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN=2e6+10;

int c,T;
int n,d;
int x[MAXN]={};
int m,ans=0;
int f[MAXN]={};

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) {
		scanf("%lld %lld",&n,&d);
		for(register int i=1;i<=n;i++) {
			scanf("%lld",&x[i]);
		}
		m=0;
		for(register int i=1;i<=n-3;i++) {
			if(x[i+3]-x[i]>d && x[i+2]-x[i]<=d && x[i+3]-x[i+1]<=d) {
				m++;
				f[m]=i;
			}
		}
		m++;
		f[m]=n-2;
		f[0]=0;
		ans=0;
		for(register int i=1;i<=m-1;i++) {
			ans=ans+(f[i]-f[i-1])*(f[i+1]-f[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

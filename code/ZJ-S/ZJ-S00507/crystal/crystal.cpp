#include <bits/stdc++.h>
#define ED cerr<<'\n';
#define TS cerr<<"I AK IOI\n";
#define cr(x) cerr<<x<<'\n';
#define cr2(x,y) cerr<<x<<" "<<y<<'\n';
#define cr3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<'\n';
#define cr4(x,y,z,w) cerr<<x<<" "<<y<<" "<<z<<" "<<w<<'\n';
#define pr(a,l,r) for(int ii=l;ii<=r;++ii) cerr<<a[ii]<<" ";ED
#define int long long
using namespace std;
const int N=5e5+5,M=2e5+5,INF=1e9;
int n,m;
int a[N];

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int sm=0,ans=0;
	for(int i=1,j=1;i<=n;++i) {
		sm+=a[i];
		while(j<=i&&a[i]*(i-j+1)-sm>m) {
			sm-=a[j],++j;
		}
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	return 0;
}
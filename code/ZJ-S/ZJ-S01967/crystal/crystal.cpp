#include<bits/stdc++.h>
#define rep(i,b,e) for(int i=(b);i<=(e);++i)
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N],b[N],sum[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	rep(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int t=1,ans=1;
	long long c=0;
	rep(i,1,n) {
		while(c+(a[i]-a[i-1])*(i-t)>m) {
			c-=a[i-1]-a[t],t++;
		}
		c+=(a[i]-a[i-1])*(i-t);
		ans=max(ans,i-t+1);
	}
	printf("%d",ans);
	return 0;
}

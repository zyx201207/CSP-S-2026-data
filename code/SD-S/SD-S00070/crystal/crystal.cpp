#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans;
ll m;
ll a[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=1;
	ans=1;
	int len;
	ll sum=0;
	while(r<=n) {
		r++;
		len=r-l+1;
		sum+=(len-1)*(a[r]-a[r-1]);
		while(sum>m) {
			sum-=a[r]-a[l];
			l++;
			len=r-l+1;
		}
		ans=max(ans,len);
	}
	printf("%d",ans);
	return 0;
}

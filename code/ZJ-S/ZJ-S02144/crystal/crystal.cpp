#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5;
int n;
long long m,a[maxn+5];
long long d[maxn+5],s[maxn+5];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	int l=1,r=2,ans=0;
	long long use=0;
	while(l<=r&&r<=n)
	{
		while(r<=n&&use+d[r]*(r-l)<=m)
		{
			use+=d[r]*(r-l);
			r++;
		}
		ans=max(ans,r-l);
		use-=a[r-1]-a[l];
		l++;
	}
	printf("%d",ans);
	return 0;
}

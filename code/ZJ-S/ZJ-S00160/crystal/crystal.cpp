#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+1000;
ll n,m,a[N],su[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int as=0;
	for(int i=1;i<=n;i++)
	{
		su[i]=su[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mi=((l+r)>>1);
			ll cishu=1ll*a[i]*(i-mi+1)-(su[i]-su[mi-1]);
			if(cishu<=m)
			{
				r=mi;
			}
			else
			{
				l=mi+1;
			}
		}
		as=max(as,i-l+1);
	}
	printf("%d\n",as);
	return 0;
}

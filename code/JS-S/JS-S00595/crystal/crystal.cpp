#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	    scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int ans=1,l=1;
	for(int i=2;i<=n;i++)
	{
		int d=1ll*(a[i]-a[i-1])*(i-l);
		if(m<d)
		{
			for(int j=l;j<=i;j++)
			{
				m+=(a[i-1]-a[j]);
				l++;
				d=1ll*(a[i]-a[i-1])*(i-l);
				if(m>=d)break;
			}
		}
		ans=max(ans,i-l+1);
		m-=d;	
	}
	printf("%lld\n",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/

#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,m,a[500005],maxx=-100000,b[500005],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
//	for(int i=1;i<=n/2;i++)
//	{
//		b[i]=a[n/2]-a[i];
//	}
	if(n%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=a[n/2])
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=a[n/2+1])
		{
			ans++;
		}
	}
	cout<<ans;
//	int mid,l=0,r=maxx;
//	while(l<r)
//	{
//		mid=(l+r)/2;
//		if(a[mid]<ans)
//		{
//			ans=mid;
//			l=mid+1;
//		}
//		else if(a[mid]==ans)
//		{
//			break;
//		}
//		else
//		{
//			r=mid-1;
//		}
//	}
	return 0;
}
//1+2+4+8+9

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],cf[500010],lc,f[500010],maxx,l,r,mid;
inline int check(int x,int y)
{
	return f[y]-(f[x-1]+(a[y]-a[x-1])*(x-1));
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]<=m)
		{
			maxx=i;
		}
		else
		{
			l=1;
			r=i-1;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(check(mid,i)>m)
				{
					l=mid+1;
				}
				else
				{
					r=mid-1;
				}
			}
			maxx=max(maxx,i-r);
		}
	} 
	cout<<maxx;
	return 0;
}
//ÎÒÄÜÄÃÆß¹³£¿£¡ 

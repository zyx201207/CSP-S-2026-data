#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],h[500010],y,ma,an;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
	{
		h[i]=h[i-1]+a[i];
	}
	for(int i = n;i>=1;i--)
	{
		int l=0,r=i,mid;
		while(l<r)
		{
			mid=(r-l)/2+l;
			if(a[i]*(i-mid+1)-(h[i]-h[mid-1])<=m)
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		if(l==0)
		{
			l=1;
		}
		ma=max(ma,1ll*i-l);
	}
	cout << ma+1;
	return 0;
}

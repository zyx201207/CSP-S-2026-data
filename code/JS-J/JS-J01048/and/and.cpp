#include <bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,m,a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (m==n)
	{
		int x=a[1];
		for (int i=2;i<=n;i++) x&=a[i];
		cout<<x;
	}
	else if (m==2)
	{
		int ma=-999999;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
	}
	else if(m==1)
	{
		int maa=-999999;
		for (int i=1;i<=n;i++) maa=max(maa,a[i]);
	}
	else if (m==3)
	{
		int ma=-999999;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				for (int ii=j+1;ii<=n;ii++) ma=max(ma,a[i]&a[j]&a[ii]);
			}
		}
		cout<<ma;
	}
	else if (m==4)
	{
		int ma=-999999;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				for (int ii=j+1;ii<=n;ii++) 
				{
					for (int jj=ii+1;jj<=n;jj++) ma=max(ma,a[i]&a[j]&a[ii]&a[jj]);
				}
			}
		}
		cout<<ma;
	}
	else if (m==5)
	{
		int ma=-999999;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				for (int ii=j+1;ii<=n;ii++) 
				{
					for (int jj=ii+1;jj<=n;jj++) 
					{
						for (int iii=jj+1;iii<=n;iii++) ma=max(ma,a[i]&a[j]&a[ii]&a[jj]&a[iii]);
					}
				}
			}
		}
		cout<<ma;
	}
	return 0;
}

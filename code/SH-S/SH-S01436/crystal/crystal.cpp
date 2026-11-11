#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans,d;
//int ch(int i)
//{
//	for (int j=1;j<=n;j++)
//	{
//		if (a[j]>i)
//		{
//			continue;
//		}
//		c++;
//		s+=i-a[j];
//	}
//	return s>m;
//}
//
//int bs()
//{
//	while (l<r)
//	{
//		int mid=l+r<<1;
//		if (ch(mid))
//		{
//			l=mid;
//		}
//		else
//		{
//			r=mid+1;
//		}
//	}
//	return l;
//}
void subtask1()
{
	int p=0;
	for (int i=1;i<=n;i++)
	{
		int t=p;
		p+=i;
		if (t<m&&m<=p)
		{
			ans=i;
			break;
		}
	}
	cout<<ans;
}
void subtask2()
{
	int p=0;
	for (int i=1;i<=n;i++)
	{
		int t=p;
		p=p+i*d;
		if (t<m&&m<=p)
		{
			ans=i;
			break;
		}
	}
	cout<<ans;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int f=1,mx=-1e12,mn=1e12,f2=1;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
		if (i==2)
		{
			d=a[i]-a[i-1];
			//ut<<d<<endl;
		}
		else if(i>2)
		{
			if (a[i-1]+d!=a[i])
			{
				f2=0;
			}
		}
		if (i!=a[i])
		{
			f=0;
		}
	}
	if (f==1)
	{
		subtask1();
		return 0;
	}
//	if (f2==1)
//	{
//		subtask2();
//		return 0;
//	}
	int mx2=0;
	//ut<<mx<<endl;
	for (int i=mn;i<=mx;i++)
	{
		int s=0,c=0;
		//ut<<i<<endl;
		for (int j=1;j<=n;j++)
		{
			if (a[j]>i)
			{
				continue;
			}
			c++;
			s+=i-a[j];
		}
		//ut<<i<<" "<<c<<" "<<s<<endl;
		if (s>m)
		{
			break;
		}
		mx2=max(mx2,c);
	}
	cout<<mx2;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
5 5
2 4 6 8 10
*/


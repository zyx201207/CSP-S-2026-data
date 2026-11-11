#include <bits/stdc++.h>
using namespace std;
int cccc,asdfjkl;
long long n,d;
long long a[2000005];
long long da[3];
long long xia[3];
int zhao(long long x)
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r-1)/2+1;
		if(a[mid]<=x)
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	return l;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cccc>>asdfjkl;
	while(asdfjkl--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]; 
		}
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				da[j]=-1;
			}
			da[2]=i; 
			while(da[2]<=n)
			{
				int flag=0;
				for(int j=0;j<3;j++)
				{
					if(da[j]==-1)	continue;
					xia[j]=zhao(a[da[j]]+d);
					if(xia[j]==da[j])
					{
						flag=1;
						break;
					}
				}
				if(flag)	break;
				for(int j=0;j<2;j++)
				{
					if(xia[j]<da[2])	continue;
					if(xia[j]<xia[2]-2)	continue;
					if(j==2)
					{
						if(xia[j-1]<da[2])
						{
							cnt+=xia[j]-da[2]+1;
						}
						else
						{
							cnt+=xia[j]-xia[j-1];
						}
					}
				}
				int uo=2;
				for(int j=xia[2];j>max(xia[2]-3,da[2]);j--)
				{
					da[uo]=j;
					uo--;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}

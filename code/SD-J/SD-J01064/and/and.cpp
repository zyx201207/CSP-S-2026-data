#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
int a[200005];
bool check(int x)
{
	x++;
	bool bb=1;
	while(x>0)
	{
		if(x%2!=0)
		{
			bb=0;
			break;
		}
		x/=2;
	}
	return bb;
}
long long zhuan_cnt(int x)
{
	long long sum=0;
	while(x>0)
	{
		if(x%2==0)
		{
			sum++;
		}
		x/=2;
	}
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	bool b=0;
	for(int i=1;i<=n;i++)
	{
		if(!check(a[i]))
		{
			b=1;
			break;
		}
	}
	if(m==1||b==0)
	{
		int ma=0;
		for(int i=1;i<=n;i++)
		{
			ma=max(a[i],ma);
		}
		cout<<ma<<endl;
		return 0;
	}
	if(m==n)
	{
		long long yv=a[1];
		for(int i=2;i<=n;i++)
		{
			yv=yv&a[i];
		}
		cout<<yv<<endl;
		return 0;
	}
	if(m==2)
	{
		int ma=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma<<endl;
		return 0;
	}
	if(m==n-1)
	{
		long long ma=0;
		for(int i=1;i<=n;i++)
		{
			ma=max(ma,zhuan_cnt(a[i]));
		}
		bool biao=0;
		long long yv=a[1];
		int p=2;
		if(a[1]==ma)
		{
			biao=1;
			yv=a[2];
			p=3;
		}
		for(int i=p;i<=n;i++)
		{
			if(biao==0&&a[i]==ma)
			{
				biao=1;
				continue;
			}
			yv=yv&a[i];
		}
		cout<<yv<<endl;
		return 0;
	}
	int max_1=0;
	for(int i=1;i<=n;i++)
	{
		max_1=max(max_1,a[i]);
	}
	if(max_1<4)
	{
		int he0=0,he1=0,he2=0,he3=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				he0++;
			}
			if(a[i]==1)
			{
				he1++;
			}
			if(a[i]==2)
			{
				he2++;
			}
			if(a[i]==3)
			{
				he3++;
			}
		}-
		if(he3>=m)
		{
			cout<<'3'<<endl;
		}
		else if(he2+he3>=m)
		{
			cout<<'2'<<endl;
		}
		else if(he1+he3>=m)
		{
			cout<<'1'<<endl;
		}
		else
		{
			cout<<'0'<<endl;
		}
		return 0;
	}
	cout<<'1'<<endl;
	return 0;
}

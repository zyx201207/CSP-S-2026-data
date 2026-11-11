#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m;
long long a[MAXN],num=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		num=max(num,a[i]);
	}
	if(m==1)
	{
		cout << num;
		return 0;
	}
	if(m==n)
	{
		num=a[1];
		for(int i=2;i<=n;i++)
		{
			num=num&a[i];
		}
		cout << num;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	num=0;
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				num=max(num,a[i]&a[j]);
			}
		}
	}
	if(m==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					num=max(num,a[i]&a[j]&a[k]);
				}
			}
		}
	}
	if(m==n-1)
	{
		int y=0;
		for(int i=1;i<=n;i++)
		{
			int zd=a[1];
			if(i==1)
			{
				zd=a[2];
			}
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					zd=zd&a[j];
				}
			}
			y=max(y,zd);
		}
		cout << y;
		return 0; 
	}
	cout << num;
	return 0; 
}

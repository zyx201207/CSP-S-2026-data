#include<bits/stdc++.h>
using namespace std;
int a[2000005],m,n,mm1,mm2,sum,len1,b[2000005],p,c[2000005],len;
int an(int f)
{
	if(f==m)
	{
		for(int i=1;i<=len1;i++)
		{
			for(int j=1;j<i;j++)
			if(m%2==1)sum=max(sum,b[j]&a[i]) ;
		}
		 
	}
	if(f%2==1)
	{
		for(int i=1;i<=len1;i++)
			for(int j=1;j<i;j++)
				c[i]=b[j]&a[i];
	}
	else 
	{	
		for(int i=1;i<=len1;i++)
		{
			for(int j=1;j<i;j++)
				b[i]=c[j]&a[i];
		}
	}
	f++;
	return an(f);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>=m&&m==2)
		{
			for(int j=1;j<i;j++)
			{
				sum=max(sum,a[i]&a[j]);
				if(sum=a[i]&a[j])
				{
					mm1=a[i];
					mm2=a[j];
				}
			}
		}
		if(m==1)sum=max(sum,a[i]);
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			b[i]=a[i]&b[j];
		}
	cout<<sum;
	return 0;
} 

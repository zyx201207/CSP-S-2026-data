#include<iostream>     
#include<cmath>
using namespace std;
long long int a[500005],sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int i,j,k,n,num=0,Min=2147483647,t,m,s=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	s=s/n;
	for(i=1;i<=n;i++)
	{
		if(abs(a[i]-s)<Min)
		{
			Min=abs(a[i]-s);
			t=i;
		}
	} 
	for(i=1;i<=n;i++)
	{
		sum[i]=a[i]-a[t];
	} 
	while(m>0)
	{
		int minx=2147483647,x;
		for(i=1;i<=n;i++)
		{
			if(sum[i]>0) continue;
			if(sum[i]<minx)
			{
				minx=abs(sum[i]);
				x=i;
			}
		} 
		if(minx==2147483647)
		{
			break;
		}
		m-=minx;
		if(m<0) break;
		a[x]=a[t];
		sum[x]=2147483647;
	}
	for(i=1;i<=n;i++)
	{
		num=0;
		int minx=2147483647,f;
		for(j=1;j<=n;j++)
		{
			if(a[j]==a[t])
			{
				num++;
			}
		}
		if(num==n) break;
		for(j=1;j<=n;j++)
		{
			if(abs(sum[j])<minx)
			{
				minx=abs(sum[j]);
				f=j;
			}
		}
		if(m>=sum[f]*num)
		{
			m-=sum[f]*num;
			for(j=1;j<=n;j++)
			{
				if(abs(sum[j])==sum[f])
				{
					sum[j]=2147483647;
					a[j]=a[t];
				}
				else
				{
					sum[j]-=sum[f];
				}
			} 
			sum[f]=2147483647;
		}
		else
		{
			break;
		}
	}
	cout<<num;
	return 0;
} 

//SN-S00460 罗天蔚 西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m=0; 
long long a[1000000];
long long p;
long long b;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	b=m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==0)
	{
		if(a[n/2]==a[n/2+1])
		{
			p=n/2;
		}
		else
		{
			p=n/2;
		}
	}
	else
	{
		p=n/2+1;
	}
	long long sum=0;
	for(long long i=1;i<=n;i++)
	{
		if(a[i]==a[p])
		{
			sum++;
		}
	}
	for(long long i=p-1;i>=1;i--)
	{
		if(a[p]-a[i]<=m)
		{
			m=m-(a[p]-a[i]);
			sum++;			
		}	
		else
		{
			break;
		}
		if(m==0)
		{
			break;
		}		
	}
	if(m==0)
	{
		cout<<sum;
		return 0;
	}
	m=b;
	int q=1;
	long long maxx=sum;
	long long sum1=0;
	while(m>0)
	{
		p=p+q;
		m=b;
		sum1=0;
		for(long long i=1;i<=n;i++)
		{
			if(a[i]==a[p])
			{
				sum1++;
			}
		}
		for(long long i=p-1;i>=1;i--)
		{
			if(a[p]-a[i]<=m)
			{
				m=m-(a[p]-a[i]);
				sum1++;			
			}	
			else
			{
				break;
			}
			if(m==0)
			{
				break;
			}		
		}
		if(sum1>maxx)
		{
			maxx=sum1;
		}
		q++;
	}
	cout<<maxx;
	return 0;
}

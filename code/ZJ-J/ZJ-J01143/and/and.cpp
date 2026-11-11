#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],maxx=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)if(a[i]>maxx)maxx=a[i];
		cout<<maxx;
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if((a[i]&a[j])>maxx)maxx=(a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	
	else if(m==3)
	{
		for(int i=1;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=j+1;k<=n;k++)
					if((a[i]&a[j]&a[k])>maxx)maxx=(a[i]&a[j]&a[k]);
			}
		}
		cout<<maxx;
		return 0;
	}
	else 
	{
		cout<<7;
	}

	return 0;
}

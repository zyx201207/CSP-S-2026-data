#include<bits/stdc++.h>
using namespace std;
long long a[200010],n,m;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	long long an=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(i==0)
			an=a[i];
		else
			an=an&a[i];	
	}
	sort(a,a+n,cmp);
	if(m==1)
	{
		cout<<a[0];
		return 0;
	}
	else if(m==n)
	{
		cout<<an;
		return 0;
	}
	else if(m==2)
	{
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				long long k=a[i]&a[j];
				ans=max(ans,k);
			}
		}
		cout<<ans;
		return 0;
	}	
	else
	{
		long long ans=a[0];
		for(int i=1;i<m;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

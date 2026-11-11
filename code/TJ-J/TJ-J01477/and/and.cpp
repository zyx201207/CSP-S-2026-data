#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=200005;
int a[N];
int erjin(int x)
{
	int sum=0;
	while(x>0)
	{
		if(x%2==1)
		{
			sum++;
			x/=2;
		}
		else
		{
			x/=2;
		}
	}
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		int maxn=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>maxn)
			{
				maxn=a[i];
			}
		}
		cout<<maxn;
	}
	else if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else
	{
		int maxn=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]&a[j]>maxn)
				{
					maxn=a[i]&a[j];
				}
			}
		}
		cout<<maxn;
	}
	return 0;
}

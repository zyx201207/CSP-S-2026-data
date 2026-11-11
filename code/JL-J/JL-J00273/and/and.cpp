#include<bits/stdc++.h>
using namespace std;
#define N 200005
long long a[N];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,ans=0,_max,_min;
	cin>>n>>m;
	cin>>a[0];
	_max=a[0];
	_min=a[0];
	for(long long i=1;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>_max)
		{
			_max=a[i];
		}
		else if(a[i]<_min)
		{
			_min=a[i];
		}
	}
	if(n==m)
	{
		ans=a[0];
		for(long long i=1;i<n;i++)
		{
			ans=ans&a[i];
		}
	}
	else if(n-1==m)
	{
		ans=a[0];
		for(long long i=1;i<n;i++)
		{
			if(a[i]==_min)continue;
			ans=ans&a[i];
		}
	}
	else if(m==1)
	{
		ans=_max;
	}
	else if(m==2)
	{
		ans=0;
		for(long long i=0;i<n;i++)
		{
			for(long long j=0;j<n;j++)
			{
				if(i!=j)
				{
					long long t=a[i]&a[j];
					if(t>ans)ans=t;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

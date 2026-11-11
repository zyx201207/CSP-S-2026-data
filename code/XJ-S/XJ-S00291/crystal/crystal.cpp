#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010]={1},k,flag,v,ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	v=a[1]-a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]-a[i-1]!=v)
		{
			flag=1;
		}
	}
	if(flag==1)
	{
		for(int i=n-1;i>=1;i--)
		{
			int u=m;
			for(int j=i-1;j>=0;j--)
			{
				if(a[i]-a[j]==0)
				{
					b[k]++;
				}
				else
				{
					if(a[i]-a[j]<=m)
					{
						b[k]++;
						u=u-(a[i]-a[j]); 
					}
				}
			}
			k++;
		}
		sort(b,b+k);
		cout<<b[k-1];
	}
	else
	{
		if(m-((v+a[n-1]-a[0])*n/2)>=0)
		{
			cout<<n;
		}
		else
		{
			for(int i=1;i<n;i++)
			{
				if(m-i*v>=0)
				{
					m=m-i*v;
					ans++;
				}
				else
				{
					cout<<ans;
					return 0;
				}
			}
		}
	}
	return 0;
}

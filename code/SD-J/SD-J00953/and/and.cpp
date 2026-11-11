#include<bits/stdc++.h>
using namespace std;
int n,m,a[200020],b[40];
int s[200010],ss[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=-1,p=a[1];
	for(int k=1;k<=n;k++)
	{
		cin>>a[k];
		p=p&a[k];
		maxx=max(maxx,a[k]);
	}
	int u=maxx,cnt=0;
	while(u)
	{
		cnt++;
		u/=2;
	}
	s[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		s[i]=s[i-1]&a[i];
	}
	ss[n]=a[n];
	for(int i=n-1;i>=1;i--)
	{
		ss[i]=ss[i+1]&a[i];
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	else if(m==n)
	{
		cout<<p;
		return 0;
	}
	else if(m==2)
	{
		int maxn=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n,j!=i;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	else if(m==3)
	{
		int maxn=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n&&j!=i;j++)
			{
				for(int k=1;k<=n&&k!=j&&k!=i;k++)
				maxn=max(maxn,a[i]&a[j]&a[k]);
			}
		}
		cout<<maxn;
	}
	else if(m==n-1)
	{
		int maxn=-1;
		for(int i=1;i<=n;i++)
		{
			if(i!=1)
			maxn=max(maxn,s[i-1]&ss[i+1]);
		}
	}
	else
	{
		cout<<pow(2,cnt);
	}
	return 0;
}

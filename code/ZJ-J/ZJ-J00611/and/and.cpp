#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long maxx,a[N];
inline void dfs(int x,long long sum,int p)
{
	if(x==m+1)
	{
		maxx=max(maxx,sum);
		return ;
	}
	for(int i=p+1;i<=n;i++)
	{
		dfs(x+1,(sum&a[i]),i);
	}
}
inline long long ksm(int a,int b)
{
	long long sum=1;
	while(b)
	{
		if(b&1)
		{
			sum*=a;
		}
		a*=a;
		b>>=1;
	}
	return sum;
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int f=1,f1=1,f2=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=4)
		{
			f=0;
		}
		if(a[i]>=1024)
		{
			f1=0;
		}
		if(a[i]!=ksm(2,(int)ceil(log2(a[i])))-1)
		{
			f2=0;
		}
	}
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			dfs(2,a[i],i);
		}
		cout<<maxx;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,(long long)a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		long long sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==2&&n<=2e3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,(long long)(a[i]&a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			long long sum;
			if(i==1)
			{
				sum=a[2];
			}
			else
			{
				sum=a[1];
			}
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				sum&=a[j];
			}
			maxx=max(maxx,sum);
		}
		cout<<maxx;
		return 0;
	}
	if(f2)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	long long sum=a[1];
	for(int i=2;i<=m;i++)
	{
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long b[200005];
void work1()
{
	long long ans=-1;
	for(int i=1;i<=m-1;i++)
	{
		long long re=-1;
		int d1,d2;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(a[j]&a[k]>re&&j!=k)
				{
					re=a[j]&a[k];
					d1=j,d2=k;
				}
			}
		}
		a[d1]=0,a[d2]=0;
		ans=max(ans,re);
	}
	cout<<ans;
} 
void work2()
{
	sort(a+1,a+1+n);
	long long ans=a[n];
	for(int i=n-1;i>=n-m+1;i--)
	{
		ans&=a[i]; 
	} 
	cout<<ans;
} 
void work3()
{
	long long n_[200005];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=j+i;j++)
		{
			n_[j]=i;
		}
	}
	long long mx=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>mx)
		{
			mx=a[i];
		}
	}
	long long ans=mx&n_[m];
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	cin>>n>>m;
	bool op=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2000)
	{
		work1();
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]%2==0)
			{
				op=1;
				break;
			}
		}
		if(op)
		{
			work3();
		}
		else
		{
			work2();
		}
	}
	return 0;	
} 

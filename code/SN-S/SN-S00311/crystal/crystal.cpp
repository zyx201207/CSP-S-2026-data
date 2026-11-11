#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool A=true,B=true; 
	long long n,m;
	cin>>n>>m;
	int a[n+1],b[n+1];
	a[0]=0;
	b[0]=0;
	b[1]=0;
	int temp=0,ans=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
		{
			A=false;
		}
		if(i==2)
		{
			temp=a[2]-a[1];
			B=true;
		}
		else if(a[i]-a[i-1]!=temp)
		{
			B=false;
		}
	}
	if(A)
	{
		for(long long i=1;m>0;i++)
		{
			m-=i;
			ans=i;
		}
		cout<<ans;
		return 0;
	}
	if(!A&&B)
	{
		for(long long i=1;m>0;i++)
		{
			m-=i*temp;
			ans=i;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1]+b[i-1];
	}
	int maxans=-1,x=0;
	for(int i=2;i<=n;i++)
	{
		int m1=m;
		ans=0;
		for(int j=i;j>0;j--)
		{
			m1-=b[i]-b[j];
			if(m1>=0)
			{
				ans++;
			}
			else
			{
				break;
			}
		}
		maxans=max(maxans,ans);
	}
	cout<<maxans;
	return 0;
}

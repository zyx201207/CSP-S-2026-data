#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn,k=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>100||a[i]<-100)
		{
			k=0;
		}
	}
	if(n<=5005)
	{
		sort(a+1,a+1+n,greater<int>());
		for(int i=1;i<=n;i++)
		{
			long long w,t=0;
			w=m;
			for(int j=i;j<=n;j++)
			{
				if(w>=a[i]-a[j])
				{
					w=w-(a[i]-a[j]);
					t++;
				}
				else
				break;
			}
			if(t>maxn)
			maxn=t;
		}
		cout<<maxn;
		return 0;
	}
	else
	if(k==1)
	{
		long long w,t=0,ji=0;
		
		sort(a+1,a+1+n,greater<int>());
		for(int i=-100;i<=100;i++)
		{
			w=m;
			ji=0;
			t=0;
			for(int j=1;j<=n;j++)
			{
				if(a[j]>i)
				{
					continue;
				}
				if(ji==0&&a[j]<=i)
				{
					ji=a[j];
				}
				if(w>=ji-a[j])
				{
					w=w-(ji-a[j]);
					t++;
				}
				if(w<ji-a[j])
				{
					break;
				}
			}
			if(maxn<t)
			maxn=t;
		}
		cout<<maxn;
		return 0;
	}
	else
	{
		sort(a+1,a+1+n,greater<int>());
		long long w,t=0;
		w=m;
		for(int i=1;i<=n;i++)
		{
			if(w>=a[1]-a[i])
			{
				w=w-(a[1]-a[i]);
				t++;
			}
			
			else
			{
				break;
			}
		}
		cout<<t;
		return 0;
	}
	return 0;
}

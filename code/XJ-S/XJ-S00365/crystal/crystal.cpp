#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],ans,t,x,f,f2,f3,v[500];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(i==2)
			x=a[i]-a[i-1];
		if(a[i]!=i)
			f=1;
		if(a[i]-a[i-1]!=x&&i>=2)
			f2=1;
		if(abs(a[i])>100)
			f3=1;
	}
	sort(a+1,a+1+n);
	if(f!=1)
	{
		long long i;
		for(i=1;i*(i+1)<2*m+1;i++);
		cout<<i;
		return 0;
	}
	if(f2!=1&&x!=1)
	{
		long long i;
		for(i=x;(i/x)*(i+x)<2*m+1;i++);
		cout<<i;
		return 0;
	}
	if(f3!=1)
	{
		for(int i=1;i<=n;i++)
		{
			v[a[i]+100]++;
		}
		sort(a+1,a+1+n);
		int len=unique(a+1,a+1+n)-(a+1);
		for(int i=2;i<=len;i++)
		{
			t=v[a[i]+100];
			int k=m,j=i-1;
			while(k>0&&j>=1)
			{
				if(k>=a[i]-a[j])
				{
					long long c=k/(a[i]-a[j]);
					if(c>v[a[j]+100])
						c=v[a[j]+100];
					k=k-c*(a[i]-a[j]);
					t+=c;
				}
				else
					break;
				j--;
			}
			ans=max(ans,t);
		}
		cout<<ans;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		t=1;
		int k=m,j=i-1;
		while(k>0&&j>=1)
		{
			if(k>=a[i]-a[j])
			{
				k-=(a[i]-a[j]);
				t++; 
			}
			else
				break;
			j--;
		}
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}

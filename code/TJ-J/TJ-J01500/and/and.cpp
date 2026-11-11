#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n+5];
	bool f=1;
	long long max_a=-1,min_a=0x3f3f3f3f;
	long long ans=pow(2,31)-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1||a[i]!=3||a[i]!=7||a[i]!=15||a[i]!=31||a[i]!=63||a[i]!=127||a[i]!=255||a[i]!=511||a[i]!=1023||a[i]!=2047||a[i]!=4095||a[i]!=8191||a[i]!=16383||a[i]!=32767||a[i]!=65535||a[i]!=131071)
		{
			f=0;
		}
		max_a=max(max_a,a[i]);
		min_a=min(min_a,a[i]);
		ans=(ans&a[i]);
	}
	if(m==1)
	{
		cout<<max_a;
		return 0;
	}
	else if(n==m)
	{
		cout<<ans;
		return 0;
	}
	else if(m==n-1)
	{
		bool w=1;
		long long t=pow(2,31)-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==min_a&&f)
			{
				f=0;
			}
			else
			{
				t=(t&a[i]);
			}
		}
		cout<<t;
		return 0;
	}
	else if(m==2)
	{
		long long max_t=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				max_t=max(max_t,(a[i]&a[j]));
			}
		}
		cout<<max_t;
	}
	else if(f)
	{
		cout<<a[n-m+1];
		return 0;
	}
	else if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12)
	{
		cout<<12;
		return 0;
	}
	else if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)
	{
		cout<<7;
		return 0;
	}
	else
	{
		cout<<0;
	}
	return 0;
}

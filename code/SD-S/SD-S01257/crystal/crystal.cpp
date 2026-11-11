#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[500100];
long long summ[500100];
long long m;
int n;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	summ[0]=0;
	for(int i=1;i<=n;i++)
	{
		summ[i]=summ[i-1]+a[i];
	}
	long long ned=0,f=0;
	int ans;
	for(ans=2;ans<=n;ans++)
	{
		f=0;
		for(int i=ans;i<=n;i++)
		{
			ned=ans*a[i]-summ[i]+summ[i-ans];
			if(ned<=m)
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			cout<<ans-1;
			return 0;
		}
	}
	if(ans==2)
	{
		cout<<1;
	}
	if(ans>=n)
	{
		cout<<n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


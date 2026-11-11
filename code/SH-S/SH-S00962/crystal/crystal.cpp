#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b[100005],ans;


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int flag=1;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (i>2)
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])
				flag=0;
	}
	if(flag)
	{
		int d=0,e=1;
		for(int i=1;i<n;i++)
		{
			d+=i*(a[2]-a[1]);
			if(d>m)
				break;
			e=i+1;
		}
		cout<<e;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++)
	{
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
	}
	for(long long i=1;i<=n;i++)
	{
		for (long long j=i+ans;j<=n;j++)
		{
			if((b[j]-b[i])/max(j-1,(long long)1)*(j-i)<=m)
			{
				ans=max(ans,j-i+1);
			}
			else
			{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

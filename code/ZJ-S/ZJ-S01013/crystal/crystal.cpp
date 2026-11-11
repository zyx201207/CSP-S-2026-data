#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
long long ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	int p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		if(i==2)
		{
			p=a[i]-a[i-1];
		}
		if(i>2&&p!=a[i]-a[i-1])
		{
			flag=false;
		}
	}
	if(flag&&n>5000)
	{
		long long x=0;
		long long l=0;
		while(x<=m)
		{
			x+=p;
			l++;
			p*=2;
		}
		cout<<min(l,n);
		return 0;
	}
	for(long long i=2;i<=n;i++)
	{
		for(long long j=0;j<i;j++)
		{
			if((b[i-1]-b[j]+m)>=a[i]*(i-j-1))
			{
				ans=max(ans,i-j);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

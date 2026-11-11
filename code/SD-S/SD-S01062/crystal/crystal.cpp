#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[500005],q[500005],ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	q[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		q[i]=q[i-1]+a[i];
	}
	long long d,pos;
	for(int i=1;i<=n;i++)
	{
		if(q[i-1]+m<=a[i]*i)
		{
			d=a[i];
			pos=i+1;
			ans=i;
			break;
		}
	}
	for(int i=pos;i<=n;i++)
	{
		if(a[i]==d)
		{
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

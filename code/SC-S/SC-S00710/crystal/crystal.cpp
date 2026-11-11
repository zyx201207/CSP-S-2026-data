#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,qw=0,maxn=0;
	long long m,qa;
	int a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		qa=m;
		qw=0;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]!=a[i])
			{
				break;
			}
			qw++;
		}
		for(int j=i;j>=1;j--)
		{
			if(qa>=a[i]-a[j])
			{
				qw++;
				qa-=(a[i]-a[j]);
			}
		}
		maxn=max(maxn,qw);
	}
	cout<<maxn;
}
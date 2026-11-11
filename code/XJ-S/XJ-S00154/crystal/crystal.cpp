#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int zd;
	if(n%2==0)
	{
		zd=n/2;
	}
	else
	{
		zd=(n-1)/2+1;
	}
	for(int i=zd+1;i<=n;i++)
	{
		if(a[i]==a[zd])
		{
			cnt++;
		}
	}
	if(n%2==0)
	{
		cout<<n/2+cnt;
	}
	else
	{
		cout<<(n-1)/2+1+cnt;
	}
	return 0;
}

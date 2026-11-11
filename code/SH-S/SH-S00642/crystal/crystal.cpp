#include<bits/stdc++.h>
using namespace std;

long long i,m,n,a[500001],ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=m;i++)
	{
		if (a[i+1]>a[i])
		{
			m=m-(a[i+1]-a[i])*i;
			for(int j=1;j<=i;j++)
			{
				a[i]=a[i+1];
			}
		ans++;
		}
	}
	if (m<0)
	{
		ans--;
	}
	cout<<ans;
	return 0;
}


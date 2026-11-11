#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll n,m,minn=1e18+2,a[500005],x[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		minn=min(minn,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		a[i]+=abs(minn);
		x[i]=x[i-1]+a[i];
	}
	for(int i=n;i>=1;i--) 
	{
		for(int j=0;j+i<=n;j++)
		{
			if(a[i+j]*(i)-(x[i+j]-x[j])<=m)
			{
				cout<<i;
				return 0;
			}
		}
	}
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,l=1,ans=0,u3;
long long a[500005];
long long u1[500005];
long long u2[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		u1[i]=a[i]-a[i-1];
	}
	for(long long i=1;i<=n;i++)
	{
		u2[i]=u2[i-1]+(u1[i]*(i-1));
	}
	for(long long r=1;r<=n;r++)
	{
		while(1)
		{
			u3=u2[r]-u2[l-1]-(a[r]-a[l-1])*(l-1);
			if(u3<=m)
			{
				ans=max(ans,(r-l+1));
				break;
			}
			l++;
		}
	}
	cout<<ans;
	return 0;
}

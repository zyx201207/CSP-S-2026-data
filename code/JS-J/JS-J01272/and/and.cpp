#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N],ans=0;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		ans=a[1];
		for(int i=1;i<=n;i++)
		{
			if(i==1)ans=a[2];
			for(int j=1;j<=n;j++)
			{
				if(j==i)continue;
				ans=ans&a[j];
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		int k=0;
		for(int i=1;i<=n;i++)
		{
			k=a[i];
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,k&a[j]);
			}
		}
		cout<<ans;
	}
	return 0;
}

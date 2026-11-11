#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
int c[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		int maxx=a[1];
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int tmp;
			if(i==1)
			{
				tmp=a[2];
			}
			else
			{
				tmp=a[1];
			}
			for(int j=tmp+1;j<=n;j++)
			{
				if(j==i)
				{
					continue;
				}
				else
				{
					tmp&=a[j];
				}
			}
			ans=max(ans,tmp);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		c[i]=a[n-i+1];
	}
	int ans=c[1];
	for(int i=2;i<=m;i++)
	{
		ans&=c[i];
	}
	cout<<ans;
	return 0;
}
